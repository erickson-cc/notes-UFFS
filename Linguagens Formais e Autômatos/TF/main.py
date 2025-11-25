# Gerar um AFD livre de estados inalcançáveis e mortos
# Entrada: Arquivo com a relação de tokens e/ou GRs de uma linguagem
# Saída: AFD e mínimo sem a aplicação de classes de equivalência entre estados.

afnd = {}
estados_finais = set()      # conjunto para guardar estados finais
contador_estados = 0        # Variável para gerar nomes de estados (Qxx)

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
            #continue
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


arquivo = "fonte.txt"

try:
    with open(arquivo, 'r', encoding='utf-8') as arquivo:
                            # embora não tenha caracteres especiais no arquivo,
                            # utilizei a codificação utf-8
        for linha in arquivo:
            iterarLinha(linha)

    print(f"Estados finais: {estados_finais}")
except FileNotFoundError:
    print("Erro: O arquivo"+arquivo+"não foi encontrado")
