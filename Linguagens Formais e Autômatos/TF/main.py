# Gerar um AFD livre de estados inalcançáveis e mortos
# Entrada: Arquivo com a relação de tokens e/ou GRs de uma linguagem
# Saída: AFD e mínimo sem a aplicação de classes de equivalência entre estados.

afnd = {}
estados_finais = set()      # conjunto para guardar estados finais
contador_estados = 0        # Variável para gerar nomes de estados (Qxx)


#------------vvvvvvvvv CRIAÇÃO DO AUTÔMATO vvvvvvvvv------------
def processarGramatica(linha):
    # Apenas o estado inicial <S> é compartilhado por todas as regras
    global contador_estados
    print("Processando Gramática na linha:"+linha)
    lados = linha.split("::=") #[,] esquerdo = <S> ; direito = a<A> | b<A> | ε
    esquerdo = lados[0].strip().replace("<","").replace(">","")
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
            estado = pedacos[1].replace(">","").strip() # tira o estado destino
            
            if simbolo not in afnd[esquerdo]:
                afnd[esquerdo][simbolo] = []

            afnd[esquerdo][simbolo].append(estado)

        elif "<" not in p and ">" not in p and len(p)==1:
            # if caso a produção seja apenas terminal
            simbolo = p
            contador_estados += 1
            novo_estado = f"Q{contador_estados}"
            if novo_estado not in afnd:
                afnd[novo_estado] = {}
            if simbolo not in afnd[esquerdo]:
               afnd[esquerdo][simbolo] = []
            afnd[esquerdo][simbolo].append(novo_estado)
            estados_finais.add(novo_estado)
            

        else:
            print("Problema na leitura das produções")
            break

    print(f"Processamento finalizado. Estado: {esquerdo}, Transições: {afnd[esquerdo]}")


def processarToken(linha):
    global contador_estados
    token = linha.strip()
    print("Processando Token na linha:"+linha)

    estado_atual = "S"

    if "S" not in afnd:
        afnd["S"] = {}

    for c in token:         # para cada letra, iniciar um caminho novo.
        contador_estados += 1
        novo_estado = f"Q{contador_estados}" 
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
    print(f"Token '{token}' finalizado no estado {estado_atual}")

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
#------------vvvvvvvvv    DETERMINIZAÇÃO   vvvvvvvvv------------
def alfabetoAFND(afnd):
    alfabeto = set()
    for estado in afnd:
        for simbolo in afnd[estado]:
            alfabeto.add(simbolo)
    return list(alfabeto)

def determinizar(afnd, estados_finais):
    print("Iniciando determinização do AFND")
    afd = {}
    estado_inicial = frozenset(['S']) # congela a lista
    fila = [estado_inicial] # fila de processamento de estados
    estados_processados = set()
    estados_processados.add(estado_inicial)
    estados_finais_afd = set() # estados finais determinizados
    alfabeto = alfabetoAFND(afnd)

    while fila:
        conjunto_atual = fila.pop(0) # next
        nome_estado = "["+"_".join(sorted(list(conjunto_atual)))+"]" # [Q1_Q8]

        if nome_estado not in afd:
            afd[nome_estado] = {}

        # Verifica se esse conjunto contém algum estado que era final no original
        # Se sim, adiciona aos finais do AFD
        # --- LÓGICA AQUI: itere sobre conjunto_atual e cheque se está em finais_afnd ---
        for i in conjunto_atual:
            if i in estados_finais:
                estados_finais_afd.add(nome_estado)

        for letra in alfabeto:
            destinos = set()
            for subestado in conjunto_atual:
                if subestado in afnd and letra in afnd[subestado]:
                    lista_destinos = afnd[subestado][letra]
                    destinos.update(lista_destinos)

            if destinos:
                novo_estado_composto = frozenset(destinos)
                nome_destino = "["+"_".join(sorted(list(novo_estado_composto)))+"]"

                afd[nome_estado][letra] = [nome_destino]

                if novo_estado_composto not in estados_processados:
                    # se o estado composto ainda não foi processado
                    estados_processados.add(novo_estado_composto)
                    fila.append(novo_estado_composto)
    return afd, estados_finais_afd



#------------vvvvvvvvv        MAIN        vvvvvvvvv------------
arquivo = "fonte.txt"

try:
    with open(arquivo, 'r', encoding='utf-8') as arquivo:
                            # embora não tenha caracteres especiais no arquivo,
                            # utilizei a codificação utf-8
        for linha in arquivo:
            iterarLinha(linha)

    print(f"Estados finais: {estados_finais}")
    # chamada da det
    afd_result, finais_afd = determinizar(afnd, estados_finais)
    print("AFND foi determinizado")
    for est, trans in afd_result.items():
        print(f"Estado {est}: {trans}")
    print(f"Estados Finais AFD: {finais_afd}")
    
except FileNotFoundError:
    print("Erro: O arquivo"+arquivo+"não foi encontrado")


