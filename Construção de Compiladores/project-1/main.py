# Autor: Erickson Giesel Müller
# Matricula: 20230001178

#------------vvvvvvvvv  VARIAVEIS GLOBAIS  vvvvvvvvv------------
afnd = {}
estados_finais = set()      # conjunto para guardar estados finais
contador_estados = -1        # variavel para gerar nomes de estados (A-B-C-D-E...)
mapa_gramatica = {"S":"S"}
rotulos_originais = {}
arquivo = "fonte.txt"
entrada = "entrada.txt"

#------------vvvvvvvvv CRIACAO DO AUTOMATO vvvvvvvvv------------
def processarGramatica(linha):
    # Apenas o estado inicial <S> e compartilhado por todas as regras
    # global contador_estados
    print("Processando Gramatica na linha:"+linha+"...")
    lados = linha.split("::=") #[,] esquerdo = <S> ; direito = a<A> | b<A> | epsilon
    nome_origem = lados[0].strip().replace("<","").replace(">","")

    if nome_origem in mapa_gramatica:
        esquerdo = mapa_gramatica[nome_origem]
    else:
        esquerdo = obterProxNome()
        mapa_gramatica[nome_origem] = esquerdo

    direito = lados[1].strip()
    producoes = direito.split("|")

    if esquerdo not in afnd:
        # se o estado ainda nao existe no dicionario
        afnd[esquerdo] = {}

    for p in producoes:
        p = p.strip()

        if p == "ε": # Caso seja produçao vazia
            estados_finais.add(esquerdo)
            rotulos_originais[esquerdo] = "variavel" # colocar no relatorio
            continue
        elif "<" in p and ">" in p: # Caso seja x<X>
            pedacos = p.split("<") # separa o lado esquerdo do direito
            simbolo = pedacos[0].strip()
            nome_destino = pedacos[1].replace(">","").strip() # tira o estado destino
            if nome_destino in mapa_gramatica:
                # testar para ver se nao esta interferindo nos estados
                # o ideal seria criar sempre um novo estado ?
                estado_destino = mapa_gramatica[nome_destino]
            else:
                estado_destino = obterProxNome()
                mapa_gramatica[nome_destino] = estado_destino
            
            if simbolo not in afnd[esquerdo]:
                afnd[esquerdo][simbolo] = []

            afnd[esquerdo][simbolo].append(estado_destino)

        elif "<" not in p and ">" not in p and len(p)==1:
            # if caso a producao seja apenas terminal
            simbolo = p
            novo_estado = obterProxNome()
            if novo_estado not in afnd:
                afnd[novo_estado] = {}
            if simbolo not in afnd[esquerdo]:
               afnd[esquerdo][simbolo] = []
            afnd[esquerdo][simbolo].append(novo_estado)
            estados_finais.add(novo_estado)
            rotulos_originais[esquerdo] = "variavel" # colocar no relatorio
            

        else:
            print("Problema na leitura das producoes")
            break

    print(f"Processamento do estado {esquerdo} finalizado.")


def processarToken(linha):
    # global contador_estados
    token = linha.strip()
    print("Processando Token na linha:"+linha+"...")

    estado_atual = "S"

    if "S" not in afnd:
        afnd["S"] = {}

    for c in token:         # para cada letra, iniciar um caminho novo.
        novo_estado = obterProxNome()

        if novo_estado not in afnd:
            # inicializar novo estado
            afnd[novo_estado] = {}
        # transicao atual->novo
        if c not in afnd[estado_atual]:
            #  caso a letra nao esta na lista de transicoes
            afnd[estado_atual][c] = []
        ##
        afnd[estado_atual][c].append(novo_estado)

        estado_atual = novo_estado
    estados_finais.add(estado_atual)
    rotulos_originais[estado_atual] = "palavra reservada" # colocar no relatorio (guarda a label do estado)
    print(f"Processamento do token '{token}' finalizado.")

def gerarNomeEstado(n):
    nome = ""
    while n>=0:
        nome = chr(n%26+65)+nome # gera o estado em ordem alfabetica
        n = n//26 -1 # caso n>26 -> nome=AA,AB,AC...

    if nome == "S":
        nome = gerarNomeEstado(n+1) # o estado S e fixo para o estado inicial

    return nome

def obterProxNome():
    global contador_estados
    contador_estados += 1
    nome = gerarNomeEstado(contador_estados)
    if nome == "S":
        contador_estados += 1
        nome = gerarNomeEstado(contador_estados)
    return nome

def iterarLinha(linha):
    linha = linha.strip()   # quebra de linha
                            # sem o strip, uma linha vazia vai ser processada
    if not linha:
        return

    if "::=" in linha:
        processarGramatica(linha)
    else:
        processarToken(linha)
#------------^^^^^^^^^ CRIACAO DO AUTOMATO ^^^^^^^^^------------
#------------vvvvvvvvv       IMPRESSAO     vvvvvvvvv------------
def alfabetoAFND(afnd):
    alfabeto = set()
    for estado in afnd:
        for simbolo in afnd[estado]:
            alfabeto.add(simbolo)
    return list(alfabeto)

def imprimir_automato(automato, finais):
    print("-" * 50)
    print(f"ESTADO   | TRANSICOES")
    print("-" * 50)

    # Ordena para 'S' aparecer primeiro ou ficar alfabetico
    estados_ordenados = sorted(automato.keys())
    
    # Se 'S' estiver na lista, move para o inicio
    if 'S' in estados_ordenados:
        estados_ordenados.remove('S')
        estados_ordenados.insert(0, 'S')

    for estado in estados_ordenados:
        # Define marcadores visuais
        prefixo_inicial = "-> " if estado == "S" else "   "
        prefixo_final = "*" if estado in finais else " "
        
        nome_formatado = f"{prefixo_inicial}{prefixo_final}{estado}"
        
        # Monta string das transicoes
        lista_transicoes = []
        if estado in automato:
            for simbolo, destinos in automato[estado].items():
                # Formata a lista de destinos ex: a->{A, B}
                destinos_str = ", ".join(destinos)
                lista_transicoes.append(f"'{simbolo}'->{{{destinos_str}}}")
        
        str_transicoes = " | ".join(lista_transicoes)
        alinhar_espaco = 5-len(estado) 
        print(f"{nome_formatado}"+" "*alinhar_espaco+f"| {str_transicoes}")
    
    print("="*50 + "\n")

#------------^^^^^^^^^       IMPRESSAO     ^^^^^^^^^------------
#------------vvvvvvvvv    DETERMINIZACAO   vvvvvvvvv------------
def determinizar(afnd, estados_finais):
    print("Iniciando determinizacao do AFND...")
    afd = {}
    estado_inicial = frozenset(['S']) # congela a lista
    fila = [estado_inicial] # fila de processamento de estados que ainda nao foram analisados
    estados_processados = set()
    estados_processados.add(estado_inicial) # para evitar loop infinito processando o mesmo estado composto infinitas vezes
    estados_finais_afd = set() # estados finais determinizados
    rotulos_afd = {} # relatorio, os estados se fundem labelOriginal -> labelComposto
    alfabeto = alfabetoAFND(afnd)

    while fila:
        conjunto_atual = fila.pop(0) # next
        nome_estado = "_".join(sorted(list(conjunto_atual))) # [A_B], tentei adicionar os "[]"+"[]" mas isso dificulta a impressao

        if nome_estado not in afd:
            # se o estado composto ainda nao existe no dicionario, cria
            afd[nome_estado] = {}

        for i in conjunto_atual:
            #verifica se o estado composto e final, se algum dos estados do conjunto_atual e final
            if i in estados_finais:
                estados_finais_afd.add(nome_estado)
                if i in rotulos_originais: # logica das labels do afd
                    rotulos_afd[nome_estado] = rotulos_originais[i]
                    if "palavra reservada" in rotulos_originais[i]:
                        break

        for letra in alfabeto:
            # percorre cada subestado
            destinos = set()
            for subestado in conjunto_atual:
                if subestado in afnd and letra in afnd[subestado]:
                    # se o subestado tem transicao com essa letra
                    # pega os destinos possiveis no AFND
                    lista_destinos = afnd[subestado][letra]
                    # adiciona oa conjunto de destinos do novo estado composto
                    destinos.update(lista_destinos)

            if destinos: # se encontrou destino para o terminal
                novo_estado_composto = frozenset(destinos)
                nome_destino = "_".join(sorted(list(novo_estado_composto)))
                # cria a transicao do afd A -x-> B
                # como no AFD o destino e unico, e usada uma lista de 1 elemento
                afd[nome_estado][letra] = [nome_destino]

                if novo_estado_composto not in estados_processados:
                    # se o estado composto ainda nao foi processado Estado Novo
                    # marca como visitado e adiciona na fila para ser processado
                    estados_processados.add(novo_estado_composto)
                    fila.append(novo_estado_composto)
    return afd, estados_finais_afd, rotulos_afd

#------------^^^^^^^^^    DETERMINIZACAO   ^^^^^^^^^------------
#------------vvvvvvvvv    ESTADO DE ERRO   vvvvvvvvv------------
def addEstadoErro(afd, alfabeto, estados_finais):
    nome_erro = "_"# para melhor visualizar, o estado de erro e apenas um underline
    p_erro = False

    # Listar estados existentes
    estados_existentes = list(afd.keys())
    # Percorrer o automato procurando falhas
    for estado in estados_existentes:
        for letra in alfabeto:
            if letra not in afd[estado]:
                p_erro = True
                afd[estado][letra] = [nome_erro] #transicao para o erro

    # definir o estado ERRO
    if p_erro:
        afd[nome_erro] = {}
        for letra in alfabeto:
            afd[nome_erro][letra] = [nome_erro]
    #
    # estados_finais.add(nome_erro) # Removido pois nao add o estado de erro ao estado de aceitacao
    return afd, estados_finais

#------------vvvvvvvvv     ANALISADOR LEXICO     vvvvvvvvv------------
def ler_entrada():
    try:
        with open(entrada, 'r', encoding='utf-8') as entradaanal:
            conteudo = entradaanal.read()
    except FileNotFoundError:
        print("Erro: O arquivo"+entrada+"nao foi encontrado")
        return
    return conteudo
def imprimir_fita(fita):
    print(f"\nFita: {' '.join(fita)} $")
def imprimir_ts(tabela_simbolos):
    print("-"*25+" TABELA DE SIMBOLOS "+"-"*25)
    print(f"{'Linha':<7} | {'Id':<3} | {'Rotulo':<17} | {'Mensagem':<17} | {'Palavra'}")
    print("_"*70)
    for ts in tabela_simbolos:
        print(f"{ts['linha']:<7} | {ts['identificador']:<3} | {ts['label']:<17} | {ts['mensagem']:<17} | {ts['palavra']}")
        print("_"*70)
def analisadorLex(entrada, afd, finais_afd, rotulos_afd):
    fita = []
    tabela_simbolos = []
    linha_atual = 1
    conteudo = ler_entrada()
    i = 0
    tamanho = len(conteudo)
    while i<tamanho:
        estado_corrente = "S"
        while i < tamanho and conteudo[i] in [" ", "\n"]:
            if conteudo[i] == "\n":
                linha_atual += 1
            i += 1
        # Condicao de parada
        if i>= tamanho:
            break

        inicio_token = i
        indice_erro = -1

        # leitura do token
        while i < tamanho:
            simbolo_lex = conteudo[i]
            if simbolo_lex in [" ", "\n"]:
                break # fim do token
            #transicao
            if estado_corrente in afd and simbolo_lex in afd[estado_corrente]:
                estado_corrente = afd[estado_corrente][simbolo_lex][0]
                # a linha 216 do codigo transforma o estado em uma lista, o ndice evita analisar a lista inteira
            else:
                if estado_corrente != "_" and indice_erro == -1:
                    indice_erro = i # palavra encontrou erro aqui
                estado_corrente = "_" # estado de erro se o terminal nao tem transicao
                                    # vai seguir no estado _ até encontrar um separador
            i+= 1

        palavra_lida = conteudo[inicio_token:i]

        if estado_corrente not in finais_afd:
            if estado_corrente != "_" and indice_erro == -1:
                indice_erro = i # palavra encontrou erro no final da palavra
            estado_corrente = "_"  # EC = X pois nao final

        fita.append(estado_corrente)
        mensagem_erro = ""
        
        # Logica de label na  tabela
        if estado_corrente == "_":
            rotulo_final = "erro"
            if indice_erro != -1:
                indice_relativo = indice_erro-inicio_token
                parte_aceita = palavra_lida[:indice_relativo]
                parte_erro = palavra_lida[indice_relativo:]
                mensagem_erro = f"{parte_aceita}→{parte_erro}"
            else: # evitar fallback
                mensagem_erro = f"→{palavra_lida}"

        else:
            rotulo_temp = rotulos_afd.get(estado_corrente, "Indefinido")
            if "variavel" in rotulo_temp:   # variavel
                rotulo_final = "variavel"
            else:                           # palavra reservada
                rotulo_final = rotulo_temp

        tabela_simbolos.append({
            "linha": linha_atual,
            "identificador": estado_corrente,
            "label": rotulo_final,
            "mensagem": mensagem_erro,
            "palavra": palavra_lida
            })
    imprimir_ts(tabela_simbolos)
    imprimir_fita(fita)
                


#------------vvvvvvvvv        MAIN        vvvvvvvvv------------

try:
    with open(arquivo, 'r', encoding='utf-8') as arquivo:
                            # utf-8 para processar o simbolo epsilon
        for linha in arquivo:
            iterarLinha(linha)

    # print(f"\nEstados finais: {estados_finais}")
    # imprimir_automato(afnd, estados_finais)
    # chamada da det
    print("AFND Construido")
    afd, finais_afd, rotulos_afd = determinizar(afnd, estados_finais)
    #chamada estado_erro
    alfabeto_lista = alfabetoAFND(afnd)
    afd, finais_afd = addEstadoErro(afd, alfabeto_lista, finais_afd)
    print("AFND foi determinizado")
    imprimir_automato(afd, finais_afd)
    # print(f"Estados Finais AFD: {finais_afd}")
    analisadorLex(entrada, afd, finais_afd, rotulos_afd)
    
except FileNotFoundError:
    print("Erro: O arquivo"+arquivo+"nao foi encontrado")

