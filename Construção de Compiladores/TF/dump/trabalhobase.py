# A linguagem considerada foi a mesma do trabalho anterior
# Tokens: SE SAI FOI
# Gramatica regular: strings com (F A E I)

# A linguagem definida ficou como
# --> se {id} foi Bloco, e bloco pode ser {id} ou {id sai Bloco}  

from collections import defaultdict

EPS = 'ε'   # marcador de cadeia vazia (epsilon)
FIM = '$'   # marcador de fim de fita


# A GLC Original foi montada com defeitos de proposito
# O "Morto" é um simbolo improdutivo (nao gera cadeia de terminais)
# O "Orfao" é um simbolo inalcancavel a partir do inicio
# Na cadeira original de fato elas não existiriam, foram colocadas p demonstrar sua remoção
def gramatica_original():
    producoes = {
        'Programa': [['Lista']],
        'Lista':    [['Lista', 'Comando'],
                     ['Comando']],
        'Comando':  [['se', 'id', 'foi', 'Bloco'],
                     ['se', 'id', 'foi', 'Bloco', 'sai', 'Bloco']],  # prefixo comum
        'Bloco':    [['id'],
                     ['Morto']],
        'Morto':    [['foi', 'Morto']],            # improdutivo  -> inutil
        'Orfao':    [['se', 'id', 'foi', 'id']],   # inalcancavel -> inutil
    }
    terminais = {'se', 'sai', 'foi', 'id'}
    inicio = 'Programa'
    return producoes, terminais, inicio

def eliminar_inuteis(producoes, terminais, inicio):
    relatorio = {}

    # (a) Simbolos geradores: terminais sempre geram; um NT gera se tem
    #     ao menos uma producao cujos simbolos todos geram.
    geradores = set(terminais)
    mudou = True
    while mudou:
        mudou = False
        for A, alts in producoes.items():
            if A in geradores:
                continue
            for rhs in alts:
                if all(s in geradores for s in rhs):
                    geradores.add(A)
                    mudou = True
                    break

    relatorio['improdutivos'] = set(producoes.keys()) - geradores

    p1 = {}
    for A, alts in producoes.items():
        if A not in geradores:
            continue
        novas = [rhs for rhs in alts
                 if all((s in terminais) or (s in geradores) for s in rhs)]
        if novas:
            p1[A] = novas

    # (b) Simbolos alcancaveis a partir do inicio
    alcancaveis = {inicio}
    fila = [inicio]
    while fila:
        A = fila.pop()
        for rhs in p1.get(A, []):
            for s in rhs:
                if s not in terminais and s not in alcancaveis:
                    alcancaveis.add(s)
                    fila.append(s)
    relatorio['inalcancaveis'] = set(p1.keys()) - alcancaveis

    p2 = {A: alts for A, alts in p1.items() if A in alcancaveis}
    return p2, relatorio


# ---------------------------------------------------------------------
# 3. FATORACAO A ESQUERDA
# ---------------------------------------------------------------------

def prefixo_comum(lista_rhs):
    if not lista_rhs:
        return []
    pref = list(lista_rhs[0])
    for rhs in lista_rhs[1:]:
        novo = []
        for a, b in zip(pref, rhs):
            if a == b:
                novo.append(a)
            else:
                break
        pref = novo
        if not pref:
            break
    return pref


def novo_nome(base, existentes):
    nome = base + "'"
    while nome in existentes:
        nome += "'"
    return nome


def fatorar(producoes, inicio):
    producoes = {A: [list(r) for r in alts] for A, alts in producoes.items()}
    relatorio = []
    mudou = True
    while mudou:
        mudou = False
        for A in list(producoes.keys()):
            alts = producoes[A]
            grupos = defaultdict(list)
            for rhs in alts:
                chave = rhs[0] if rhs else EPS
                grupos[chave].append(rhs)
            for chave, grupo in grupos.items():
                if chave == EPS or len(grupo) < 2:
                    continue
                pref = prefixo_comum(grupo)
                if not pref:
                    continue
                novo = novo_nome(A, set(producoes.keys()) | {inicio})
                restantes = [rhs for rhs in alts if rhs not in grupo]
                restantes.append(list(pref) + [novo])
                producoes[A] = restantes
                producoes[novo] = [rhs[len(pref):] for rhs in grupo]  # sufixos ([] = epsilon)
                relatorio.append((A, list(pref), novo))
                mudou = True
                break
            if mudou:
                break
    return producoes, relatorio


# ---------------------------------------------------------------------
# 4. FIRST e FOLLOW
# ---------------------------------------------------------------------

def first_da_sequencia(seq, first, terminais):
    resultado = set()
    if not seq:
        return {EPS}
    todos_anulaveis = True
    for s in seq:
        fs = first.get(s, {s} if s in terminais else set())
        resultado |= (fs - {EPS})
        if EPS not in fs:
            todos_anulaveis = False
            break
    if todos_anulaveis:
        resultado.add(EPS)
    return resultado


def calcular_first(producoes, terminais):
    first = {t: {t} for t in terminais}
    for A in producoes:
        first.setdefault(A, set())
    mudou = True
    while mudou:
        mudou = False
        for A, alts in producoes.items():
            for rhs in alts:
                f = first_da_sequencia(rhs, first, terminais)
                if not f <= first[A]:
                    first[A] |= f
                    mudou = True
    return first


def calcular_follow(producoes, terminais, inicio, first):
    follow = {A: set() for A in producoes}
    follow[inicio].add(FIM)
    mudou = True
    while mudou:
        mudou = False
        for A, alts in producoes.items():
            for rhs in alts:
                for i, B in enumerate(rhs):
                    if B in terminais or B not in follow:
                        continue
                    fbeta = first_da_sequencia(rhs[i + 1:], first, terminais)
                    add = fbeta - {EPS}
                    if not add <= follow[B]:
                        follow[B] |= add
                        mudou = True
                    if EPS in fbeta and not follow[A] <= follow[B]:
                        follow[B] |= follow[A]
                        mudou = True
    return follow



# Retorna a lista de producoes disponiveis
def aumentar(producoes, inicio):
    producoes = {A: [list(r) for r in alts] for A, alts in producoes.items()}
    novo = inicio + "'"
    while novo in producoes:
        novo += "'"

    producoes[novo] = [[inicio]]
    return producoes, novo

# Pega a lista de produções que esta no formato 'Programa': ['AAA', 'BBB'] 
# e transforma em uma lista de tuplas numeradas
# Exemplo: [(0, 'Programa', ('AAA',)), (1, 'Programa', ('BBB',))]
def indexar_producoes(producoes, inicio_aum):
    prods = [(inicio_aum, tuple(producoes[inicio_aum][0]))]
    for A in producoes:
        if A == inicio_aum:
            continue
        for rhs in producoes[A]:
            prods.append((A, tuple(rhs)))
    por_nt = defaultdict(list)
    for i, (lhs, _) in enumerate(prods):
        por_nt[lhs].append(i)

    print(prods)
    return prods, por_nt


def closure(itens, prods, por_nt, terminais):
    itens = set(itens)
    fila = list(itens)
    while fila:
        pi, dot = fila.pop()
        _, rhs = prods[pi]
        if dot < len(rhs):
            B = rhs[dot]
            if B not in terminais and B in por_nt:
                for pj in por_nt[B]:
                    it = (pj, 0)
                    if it not in itens:
                        itens.add(it)
                        fila.append(it)
    return frozenset(itens)


def goto(itens, X, prods, por_nt, terminais):
    movidos = {(pi, dot + 1) for (pi, dot) in itens
               if dot < len(prods[pi][1]) and prods[pi][1][dot] == X}
    return closure(movidos, prods, por_nt, terminais) if movidos else None


def colecao_canonica(prods, por_nt, terminais, simbolos):
    I0 = closure({(0, 0)}, prods, por_nt, terminais)
    estados = [I0]
    indice = {I0: 0}
    transicoes = {}
    fila = [I0]
    while fila:
        I = fila.pop(0)
        for X in simbolos:
            J = goto(I, X, prods, por_nt, terminais)
            if J is None:
                continue
            if J not in indice:
                indice[J] = len(estados)
                estados.append(J)
                fila.append(J)
            transicoes[(indice[I], X)] = indice[J]
    return estados, indice, transicoes


# ---------------------------------------------------------------------
# 6. TABELA SLR(1)
# ---------------------------------------------------------------------

# A tabela SLR é usada para guiar o parser
# Achou X no estado Y, o que fazer? Shift para o estado Z? Reduzir pela producao W? Aceitar?
def tabela_slr(estados, transicoes, prods, terminais, follow, inicio_aum):
    acao, ir, conflitos = {}, {}, []

    def por(d, chave, valor):
        if chave in d and d[chave] != valor:
            conflitos.append((chave, d[chave], valor))
        d[chave] = valor

    for i, I in enumerate(estados):
        for (pi, dot) in I:
            lhs, rhs = prods[pi]
            
            if dot < len(rhs):
                # É um item incompleto
                a = rhs[dot]
                if a in terminais:
                    # Se o proximo simbolo é terminal, entao é um shift
                    j = transicoes.get((i, a))
                    if j is not None:
                        por(acao, (i, a), ('s', j))
            else:
                # Item completo, hora de reduzir
                if lhs == inicio_aum:
                    # Nesse caso, não reduz, aceita
                    por(acao, (i, FIM), ('acc',))
                else:
                    # Aqui reduz, adiciona a transição para cada elemento de follow do nao terminal
                    for a in follow[lhs]:
                        por(acao, (i, a), ('r', pi))

    for (i, X), j in transicoes.items():
        if X not in terminais:
            ir[(i, X)] = j

    # acao: Lista das ações disponiveis para cada estado e terminal (ex: shift, reduce, accept)
    # ir: Lista das transições para cada estado e não terminal (ex: ir para estado 5 ao ler 'Bloco')
    
    return acao, ir, conflitos


# ---------------------------------------------------------------------
# 7. RECONHECIMENTO (driver shift-reduce) + TABELA DE SIMBOLOS
# ---------------------------------------------------------------------

ROTULO_PARA_TERMINAL = {'3': 'se', '6': 'sai', '9': 'foi', '1': 'id'}


def fita_para_terminais(fita_str):
    brutos = fita_str.replace(FIM, ' ').split()
    terms = [ROTULO_PARA_TERMINAL.get(t, t) for t in brutos]
    terms.append(FIM)
    return terms


def analisar(fita, acao, ir, prods):
    # fita  -> lista de tokens de entrada, já com o '$' no final
    # acao  -> tabela ACTION: dicionário {(estado, terminal): ('s', N) | ('r', N) | ('acc',)}
    # ir    -> tabela GOTO:   dicionário {(estado, não_terminal): estado_destino}
    # prods -> lista de produções, cada uma como (lhs, rhs)
    #          ex: prods[3] = ('E', ['E', '+', 'T'])

    pilha_estados  = [0]   # pilha de estados; começa no estado inicial 0
    pilha_simbolos = []    # pilha de símbolos (terminais e não-terminais) só para visualização
    posicao_fita = 0       # cursor na fita (qual token estamos lendo)
    historico_passos = []  # log de cada passo (para imprimir o trace da análise)
    historico_reducoes = []  # ordem das reduções aplicadas (deriva a árvore / derivação à direita reversa)

    while True:
        estado_atual = pilha_estados[-1]   # estado no topo da pilha
        terminal_atual = fita[posicao_fita]                # terminal atual (lookahead)
        acao_atual = acao.get((estado_atual, terminal_atual))  # consulta a tabela ACTION

        conteudo_pilha = ' '.join(pilha_simbolos) or 'ε'  # snapshot da pilha (para o log)
        entrada_restante = ' '.join(fita[posicao_fita:])  # entrada que ainda falta consumir

        # ---- 1) Célula vazia na ACTION => erro sintático ----
        if acao_atual is None:
            historico_passos.append((conteudo_pilha, entrada_restante, 'ERRO'))
            # descobre quais terminais SERIAM aceitos nesse estado, para a mensagem de erro
            terminais_esperados = sorted({terminal for (estado, terminal) in acao if estado == estado_atual})
            return (False,
                    f"erro sintatico na posicao {posicao_fita + 1}: encontrado '{terminal_atual}', "
                    f"esperado um de {terminais_esperados}", historico_passos, historico_reducoes)

        # ---- 2) SHIFT: act = ('s', N) => empilha o terminal e vai pro estado N ----
        if acao_atual[0] == 's':
            historico_passos.append((conteudo_pilha, entrada_restante, f"empilha '{terminal_atual}' -> estado {acao_atual[1]}"))
            pilha_estados.append(acao_atual[1])   # empilha o novo estado
            pilha_simbolos.append(terminal_atual)       # empilha o símbolo lido
            posicao_fita += 1                        # avança o cursor (consome o token)

        # ---- 3) REDUCE: act = ('r', N) => aplica a produção prods[N] ----
        elif acao_atual[0] == 'r':
            nao_terminal_reduzido, corpo_producao = prods[acao_atual[1]]        # lado esquerdo e direito da produção
            # desempilha |rhs| símbolos/estados (o tamanho do lado direito)
            for _ in range(len(corpo_producao)):
                pilha_estados.pop()
                pilha_simbolos.pop()
            estado_topo_apos_reducao = pilha_estados[-1]        # estado que sobrou no topo após desempilhar
            pilha_estados.append(ir[(estado_topo_apos_reducao, nao_terminal_reduzido)])  # consulta GOTO e empilha o estado destino
            pilha_simbolos.append(nao_terminal_reduzido)              # empilha o não-terminal lhs
            corpo_formatado = ' '.join(corpo_producao) if corpo_producao else EPS
            historico_passos.append((conteudo_pilha, entrada_restante, f"reduz  {nao_terminal_reduzido} -> {corpo_formatado}"))
            historico_reducoes.append((nao_terminal_reduzido, corpo_producao))     # registra a redução

        # ---- 4) ACCEPT: act = ('acc',) => cadeia reconhecida ----
        else:  # 'acc'
            historico_passos.append((conteudo_pilha, entrada_restante, 'ACEITA'))
            return True, "cadeia ACEITA", historico_passos, historico_reducoes

def montar_tabela_simbolos(fita, fita_str):
    categorias_por_token = {'se': 'palavra_reservada', 'foi': 'palavra_reservada',
                            'sai': 'palavra_reservada', 'id': 'identificador'}
    tabela_simbolos = []
    for ordem, token in enumerate(terminal for terminal in fita if terminal != FIM):
        tabela_simbolos.append({'ordem': ordem + 1, 'token': token,
                   'categoria': categorias_por_token.get(token, '?'),
                   'tipo': '-', 'valor': '-'})
    return tabela_simbolos


# ---------------------------------------------------------------------
# IMPRESSAO DOS ARTEFATOS
# ---------------------------------------------------------------------

def fmt_gramatica(producoes, inicio):
    linhas = []
    ordem = [inicio] + [A for A in producoes if A != inicio]
    for A in ordem:
        if A not in producoes:
            continue
        corpos = [' '.join(rhs) if rhs else EPS for rhs in producoes[A]]
        linhas.append(f"  {A:<10} ::= " + " | ".join(corpos))
    return "\n".join(linhas)


def imprimir_first_follow(first, follow, producoes, inicio):
    ordem = [inicio] + [A for A in producoes if A != inicio]
    print(f"  {'NT':<10} {'FIRST':<28} FOLLOW")
    print("  " + "-" * 60)
    for A in ordem:
        if A not in producoes:
            continue
        fs = "{" + ", ".join(sorted(first[A])) + "}"
        fo = "{" + ", ".join(sorted(follow[A])) + "}"
        print(f"  {A:<10} {fs:<28} {fo}")


def imprimir_itens(estados, prods):
    for i, I in enumerate(estados):
        print(f"  I{i}:")
        for (pi, dot) in sorted(I):
            lhs, rhs = prods[pi]
            corpo = list(rhs)
            corpo.insert(dot, '.')
            print(f"      {lhs} -> {' '.join(corpo) if corpo else '.'}")

def imprimir_tabela(estados, acao, ir, terminais, nts):
    cols_t = sorted(terminais) + [FIM]
    cols_n = [n for n in nts]
    larg = 8
    head = "  " + "Est".ljust(4) + "| " + \
           " ".join(c.center(larg) for c in cols_t) + " || " + \
           " ".join(c.center(larg) for c in cols_n)
    print(head)
    print("  " + "-" * (len(head) - 2))
    for i in range(len(estados)):
        cels = []
        for t in cols_t:
            a = acao.get((i, t))
            if a is None:
                cels.append("".center(larg))
            elif a[0] == 's':
                cels.append(f"s{a[1]}".center(larg))
            elif a[0] == 'r':
                cels.append(f"r{a[1]}".center(larg))
            else:
                cels.append("acc".center(larg))
        celn = [str(ir.get((i, n), "")).center(larg) for n in cols_n]
        print("  " + str(i).ljust(4) + "| " +
              " ".join(cels) + " || " + " ".join(celn))


# ---------------------------------------------------------------------
# CONSTRUCAO COMPLETA DO PARSER
# ---------------------------------------------------------------------

def construir_parser():
    g0, terminais, inicio = gramatica_original()

    print("=" * 64)
    print("1) GRAMATICA ORIGINAL (G0)")
    print("=" * 64)
    print(fmt_gramatica(g0, inicio))

    # Objetivo: Remover os simbolos "Morto" e "Orfao", e suas producoes associadas, da gramatica.
    g1, rel_inut = eliminar_inuteis(g0, terminais, inicio)

    print("\n" + "=" * 64)
    print("2) ELIMINACAO DE SIMBOLOS INUTEIS")
    print("=" * 64)
    print(f"  Improdutivos removidos : {sorted(rel_inut['improdutivos']) or '(nenhum)'}")
    print(f"  Inalcancaveis removidos: {sorted(rel_inut['inalcancaveis']) or '(nenhum)'}")
    print("  Gramatica resultante:")
    print(fmt_gramatica(g1, inicio))

    # Objetivo: Eliminar o prefixo comum "se id foi Bloco" das producoes de Comando
    # criando um novo não terminal e as producoes associadas.
    g2, rel_fat = fatorar(g1, inicio)

    print("\n" + "=" * 64)
    print("3) FATORACAO A ESQUERDA")
    print("=" * 64)
    if rel_fat:
        for A, pref, novo in rel_fat:
            print(f"  {A}: prefixo comum '{' '.join(pref)}' -> novo NT {novo}")
    else:
        print("  (nada a fatorar)")

    print("  Gramatica final:")
    print(fmt_gramatica(g2, inicio))

    # FIRST E FOLLOW
    first = calcular_first(g2, terminais)
    follow = calcular_follow(g2, terminais, inicio, first)

    print("\n" + "=" * 64)
    print("4) FIRST e FOLLOW")
    print("=" * 64)
    imprimir_first_follow(first, follow, g2, inicio)

    g_aum, inicio_aum = aumentar(g2, inicio)
    prods, por_nt = indexar_producoes(g_aum, inicio_aum)
    nts = [A for A in g_aum if A != inicio_aum]
    simbolos = list(terminais) + list(g_aum.keys())
    estados, indice, transicoes = colecao_canonica(prods, por_nt, terminais, simbolos)

    print("\n" + "=" * 64)
    print("5) COLECAO CANONICA DE ITENS LR(0)")
    print("=" * 64)
    print("  Producoes numeradas:")
    for i, (lhs, rhs) in enumerate(prods):
        print(f"     ({i}) {lhs} -> {' '.join(rhs) if rhs else EPS}")
    print()
    imprimir_itens(estados, prods)

    acao, ir, conflitos = tabela_slr(estados, transicoes, prods, terminais, follow, inicio_aum)

    print("\n" + "=" * 64)
    print("6) TABELA SLR(1)")
    print("=" * 64)
    imprimir_tabela(estados, acao, ir, terminais, nts)
    print(f"\n  Conflitos: {conflitos if conflitos else 'NENHUM (gramatica e SLR(1))'}")

    return {'acao': acao, 'ir': ir, 'prods': prods,
            'conflitos': conflitos, 'inicio_aum': inicio_aum}


def reconhecer(fita_str, parser):
    fita = fita_para_terminais(fita_str)
    aceito, mensagem_resultado, historico_passos, _historico_reducoes = analisar(fita, parser['acao'], parser['ir'], parser['prods'])
    tabela_simbolos = montar_tabela_simbolos(fita, fita_str)

    print(f"\nFITA de entrada : {fita_str}")
    print(f"Terminais       : {' '.join(fita)}")
    print(f"\n  {'PILHA':<28} {'ENTRADA':<18} ACAO")
    print("  " + "-" * 70)
    for conteudo_pilha, entrada_restante, acao_executada in historico_passos:
        print(f"  {conteudo_pilha:<28} {entrada_restante:<18} {acao_executada}")
    print(f"\n  RESULTADO: {mensagem_resultado}")
    if aceito:
        print("\n  TABELA DE SIMBOLOS:")
        print(f"  {'Ordem':<6} {'Token':<6} {'Categoria':<18} {'Tipo':<6} Valor")
        print("  " + "-" * 48)
        for entrada_tabela in tabela_simbolos:
            print(f"  {entrada_tabela['ordem']:<6} {entrada_tabela['token']:<6} {entrada_tabela['categoria']:<18} {entrada_tabela['tipo']:<6} {entrada_tabela['valor']}")

    return aceito


if __name__ == '__main__':
    parser = construir_parser()

    print("\n" + "=" * 64)
    print("7) RECONHECIMENTO DE CADEIAS (entrada = FITA do lexico)")
    print("=" * 64)

    # Validas
    #reconhecer('3 1 9 1 $', parser)          # se id foi id
    #reconhecer('3 1 9 1 6 1 $', parser)      # se id foi id sai id
    #reconhecer('3 1 9 1 3 1 9 1 $', parser)  # dois comandos

    ## Invalidas
    reconhecer('3 9 1 $', parser)            # se foi id  (falta condicao)
    #reconhecer('1 9 1 $', parser)            # id foi id  (nao inicia com se)
    #reconhecer('3 1 9 1 6 $', parser)        # sai sem bloco


