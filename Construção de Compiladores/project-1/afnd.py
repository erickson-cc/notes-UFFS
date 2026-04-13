# Gerar um AFD livre de estados inalcançáveis e mortos
# Entrada: Arquivo com a relação de tokens e/ou GRs de uma linguagem
# Saída: AFD e mínimo sem a aplicação de classes de equivalência entre estados.
# Autor: Erickson Giesel Müller
# Matrícula: 20230001178

#------------vvvvvvvvv  VARIÁVEIS GLOBAIS  vvvvvvvvv------------
afnd = {}
estados_finais = set()      # conjunto para guardar estados finais
contador_estados = -1        # Variável para gerar nomes de estados (A-B-C-D-E...)
mapa_gramatica = {"S":"S"}
arquivo = "fonte.txt"

#------------vvvvvvvvv CRIAÇÃO DO AUTÔMATO vvvvvvvvv------------
def processarGramatica(linha):
    # Apenas o estado inicial <S> é compartilhado por todas as regras
    # global contador_estados
    print("Processando Gramática na linha:"+linha+"...")
    lados = linha.split("::=") #[,] esquerdo = <S> ; direito = a<A> | b<A> | ε
    nome_origem = lados[0].strip().replace("<","").replace(">","")

    if nome_origem in mapa_gramatica:
        esquerdo = mapa_gramatica[nome_origem]
    else:
        esquerdo = obterProxNome()
        mapa_gramatica[nome_origem] = esquerdo

    direito = lados[1].strip()
    producoes = direito.split("|")

    if esquerdo not in afnd:
        # se o estado ainda não existe no dicionário
        afnd[esquerdo] = {}

    for p in producoes:
        p = p.strip()

        if p == "ε": # Caso seja produção vazia
            estados_finais.add(esquerdo)
            continue
        elif "<" in p and ">" in p: # Caso seja x<X>
            pedacos = p.split("<") # separa o lado esquerdo do direito
            simbolo = pedacos[0].strip()
            nome_destino = pedacos[1].replace(">","").strip() # tira o estado destino
            if nome_destino in mapa_gramatica:
                # testar para ver se não está interferindo nos estados
                # o ideal seria criar sempre um novo estado ?
                estado_destino = mapa_gramatica[nome_destino]
            else:
                estado_destino = obterProxNome()
                mapa_gramatica[nome_destino] = estado_destino
            
            if simbolo not in afnd[esquerdo]:
                afnd[esquerdo][simbolo] = []

            afnd[esquerdo][simbolo].append(estado_destino)

        elif "<" not in p and ">" not in p and len(p)==1:
            # if caso a produção seja apenas terminal
            simbolo = p
            novo_estado = obterProxNome()
            if novo_estado not in afnd:
                afnd[novo_estado] = {}
            if simbolo not in afnd[esquerdo]:
               afnd[esquerdo][simbolo] = []
            afnd[esquerdo][simbolo].append(novo_estado)
            estados_finais.add(novo_estado)
            

        else:
            print("Problema na leitura das produções")
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
        # Transição atual->novo
        if c not in afnd[estado_atual]:
            #  caso a letra não está na lista de transições
            afnd[estado_atual][c] = []
        ##
        afnd[estado_atual][c].append(novo_estado)

        estado_atual = novo_estado
    estados_finais.add(estado_atual)
    print(f"Processamento do token '{token}' finalizado.")

def gerarNomeEstado(n):
    nome = ""
    while n>=0:
        nome = chr(n%26+65)+nome # gera o estado em ordem alfabética
        n = n//26 -1 # caso n>26 -> nome=AA,AB,AC...

    if nome == "S":
        nome = gerarNomeEstado(n+1) # o estado S é fixo para o estado inicial

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
#------------^^^^^^^^^ CRIAÇÃO DO AUTÔMATO ^^^^^^^^^------------
#------------vvvvvvvvv       IMPRESSÃO     vvvvvvvvv------------
def alfabetoAFND(afnd):
    alfabeto = set()
    for estado in afnd:
        for simbolo in afnd[estado]:
            alfabeto.add(simbolo)
    return list(alfabeto)

def imprimir_automato(automato, finais):
    print("-" * 50)
    print(f"ESTADO   | TRANSIÇÕES")
    print("-" * 50)

    # Ordena para 'S' aparecer primeiro ou ficar alfabético
    estados_ordenados = sorted(automato.keys())
    
    # Se 'S' estiver na lista, move para o início
    if 'S' in estados_ordenados:
        estados_ordenados.remove('S')
        estados_ordenados.insert(0, 'S')

    for estado in estados_ordenados:
        # Define marcadores visuais
        prefixo_inicial = "-> " if estado == "S" else "   "
        prefixo_final = "*" if estado in finais else " "
        
        nome_formatado = f"{prefixo_inicial}{prefixo_final}{estado}"
        
        # Monta string das transições
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

#------------^^^^^^^^^       IMPRESSÃO     ^^^^^^^^^------------
#------------vvvvvvvvv    DETERMINIZAÇÃO   vvvvvvvvv------------
def determinizar(afnd, estados_finais):
    print("Iniciando determinização do AFND")
    afd = {}
    estado_inicial = frozenset(['S']) # congela a lista
    fila = [estado_inicial] # fila de processamento de estados que ainda não foram analisados
    estados_processados = set()
    estados_processados.add(estado_inicial) # para evitar loop infinito processando o mesmo estado composto infinitas vezes
    estados_finais_afd = set() # estados finais determinizados
    alfabeto = alfabetoAFND(afnd)

    while fila:
        conjunto_atual = fila.pop(0) # next
        nome_estado = "_".join(sorted(list(conjunto_atual))) # [A_B], tentei adicionar os "[]"+"[]" mas isso dificulta a impressão

        if nome_estado not in afd:
            # se o estado composto ainda não existe no dicionário, cria
            afd[nome_estado] = {}

        for i in conjunto_atual:
            #verifica se o estado composto é final, se algum dos estados do conjunto_atual é final
            if i in estados_finais:
                estados_finais_afd.add(nome_estado)

        for letra in alfabeto:
            # percorre cada subestado
            destinos = set()
            for subestado in conjunto_atual:
                if subestado in afnd and letra in afnd[subestado]:
                    # se o subestado tem transição com essa letra
                    # pega os destinos possíveis no AFND
                    lista_destinos = afnd[subestado][letra]
                    # adiciona oa conjunto de destinos do novo estaod composto
                    destinos.update(lista_destinos)

            if destinos: # se encontrou destino para o terminal
                novo_estado_composto = frozenset(destinos)
                nome_destino = "_".join(sorted(list(novo_estado_composto)))
                # cria a transição do afd A -x-> B
                # como no AFD o destino é único, é usada uma lista de 1 elemento
                afd[nome_estado][letra] = [nome_destino]

                if novo_estado_composto not in estados_processados:
                    # se o estado composto ainda não foi processado Estado Novo
                    # marca como visitado e adiciona na fila para ser processado
                    estados_processados.add(novo_estado_composto)
                    fila.append(novo_estado_composto)
    return afd, estados_finais_afd

#------------^^^^^^^^^    DETERMINIZAÇÃO   ^^^^^^^^^------------
#------------vvvvvvvvv    ESTADO DE ERRO   vvvvvvvvv------------
def addEstadoErro(afd, alfabeto, estados_finais):
    nome_erro = "_"# para melhor visualizar, o estado de erro é apenas um underline
    p_erro = False

    # Listar estados existentes
    estados_existentes = list(afd.keys())
    # Percorrer o autômato procurando falhas
    for estado in estados_existentes:
        for letra in alfabeto:
            if letra not in afd[estado]:
                p_erro = True
                afd[estado][letra] = [nome_erro] #transição para o erro

    # definir o estado ERRO
    if p_erro:
        afd[nome_erro] = {}
        for letra in alfabeto:
            afd[nome_erro][letra] = [nome_erro]
    #
    estados_finais.add(nome_erro)
    return afd, estados_finais

#------------vvvvvvvvv        MAIN        vvvvvvvvv------------

try:
    with open(arquivo, 'r', encoding='utf-8') as arquivo:
                            # utf-8 para processar o simbolo epsilon
        for linha in arquivo:
            iterarLinha(linha)

    print(f"\nEstados finais: {estados_finais}")
    print("\nAFND:")
    imprimir_automato(afnd, estados_finais)
    # chamada da det
    afd, finais_afd = determinizar(afnd, estados_finais)
    #chamada estado_erro
    alfabeto_lista = alfabetoAFND(afnd)
    afd, finais_afd = addEstadoErro(afd, alfabeto_lista, finais_afd)
    print("\n\n----- AFND foi determinizado -----")
    print("\nAFD:")
    imprimir_automato(afd, finais_afd)
    print(f"Estados Finais AFD: {finais_afd}")
    
except FileNotFoundError:
    print("Erro: O arquivo"+arquivo+"não foi encontrado")


