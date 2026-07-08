#from analex import analisadorLex, afd, finais_afd, rotulos_afd
from analex import executar_lexico

# Como a memória do seu programa deve ficar após ler a GLC:
class AnalisadorSintatico:
    def __init__(self, fita_tokens, tabela_simbolos, caminho_glc="glc.txt"):
        self.fita = fita_tokens
        self.tabela_simbolos = tabela_simbolos
        self.glc = self.carregar_glc(caminho_glc)
        print(f"Analisador sintático iniciado com uma fita de {len(self.fita)} tokens.")
        print(f"Gramática carregada com {len(self.glc)} regras não-terminais.")

    def carregar_glc(self, caminho_arquivo):
        gramatica = {}
        try:
            with open(caminho_arquivo, 'r', encoding='utf-8') as arq:
                for linha in arq:
                    linha = linha.strip()
                    
                    # Ignora linhas vazias ou que não contenham o operador de produção
                    if not linha or "::=" not in linha:
                        continue
                    
                    # Separa o lado esquerdo (Não-Terminal) do lado direito (Produções)
                    lados = linha.split("::=")
                    esquerdo = lados[0].strip()
                    direito = lados[1].strip()
                    
                    if esquerdo not in gramatica:
                        gramatica[esquerdo] = []
                    
                    # Separa as opções alternativas divididas por '|'
                    opcoes = direito.split("|")
                    for opcao in opcoes:
                        # Divide os símbolos individuais da produção usando o espaço em branco
                        simbolos = opcao.strip().split()
                        if simbolos:
                            gramatica[esquerdo].append(simbolos)
            return gramatica
        except FileNotFoundError:
            print(f"Erro: O ficheiro de gramática '{caminho_arquivo}' não foi encontrado.")
            return {}

    def eliminar_inuteis(self):
        #Remove símbolos que não geram terminais ou que não são alcançáveis a partir do estado inicial
        print("Executando: Eliminação de Símbolos Inúteis...")
        nao_terminais = set(self.glc.keys())
        
        # --- FASE 1: Encontrar Símbolos Geradores ---
        geradores = set()
        mudou = True
        while mudou:
            mudou = False
            for nt, producoes in self.glc.items():
                if nt not in geradores:
                    for prod in producoes:
                        # Uma produção é geradora se todos os seus símbolos são terminais ou já são geradores
                        if all((simbolo not in nao_terminais) or (simbolo in geradores) for simbolo in prod):
                            geradores.add(nt)
                            mudou = True
                            break

        # Limpa as produções que dependem de não-geradores
        nova_glc = {}
        for nt, producoes in self.glc.items():
            if nt in geradores:
                novas_prods = [p for p in producoes if all((s not in nao_terminais) or (s in geradores) for s in p)]
                if novas_prods:
                    nova_glc[nt] = novas_prods
        self.glc = nova_glc
        nao_terminais = set(self.glc.keys())

        # --- FASE 2: Encontrar Símbolos Alcançáveis ---
        if not self.glc:
            return
            
        # O símbolo inicial é a primeira chave lida do arquivo
        simbolo_inicial = list(self.glc.keys())[0] 
        alcancaveis = {simbolo_inicial}
        fila = [simbolo_inicial]

        while fila:
            atual = fila.pop(0)
            if atual in self.glc:
                for prod in self.glc[atual]:
                    for simbolo in prod:
                        if simbolo in nao_terminais and simbolo not in alcancaveis:
                            alcancaveis.add(simbolo)
                            fila.append(simbolo)

        # Filtra a gramática apenas com os alcançáveis
        self.glc = {nt: prods for nt, prods in self.glc.items() if nt in alcancaveis}
        print(f"Gramática limpa. Restaram {len(self.glc)} regras.")

    def fatorar_glc(self):
        # Aplica a fatoração à esquerda para remover ambiguidades (prefixos comuns).
        print("Executando: Fatoração da GLC...")
        mudou = True
        while mudou:
            mudou = False
            novos_nao_terminais = {}
            chaves_atuais = list(self.glc.keys())

            for nt in chaves_atuais:
                producoes = self.glc[nt]
                if len(producoes) <= 1:
                    continue

                # Agrupa as produções pelo seu primeiro símbolo (prefixo de tamanho 1)
                prefixos = {}
                for prod in producoes:
                    primeiro = prod[0] if prod else "ε"
                    if primeiro not in prefixos:
                        prefixos[primeiro] = []
                    prefixos[primeiro].append(prod)

                # Procura se algum prefixo se repete em mais de uma produção
                para_fatorar = None
                for primeiro, prods in prefixos.items():
                    if len(prods) > 1:
                        para_fatorar = (primeiro, prods)
                        break

                if para_fatorar:
                    mudou = True
                    primeiro, prods = para_fatorar
                    
                    # Cria um novo nome de estado (ex: DECLARACAO')
                    novo_nt = nt + "'"
                    while novo_nt in self.glc or novo_nt in novos_nao_terminais:
                        novo_nt += "'"

                    # Remove as produções antigas e adiciona a fatorada: A -> prefixo A'
                    novas_prods_nt = [p for p in producoes if p not in prods]
                    novas_prods_nt.append([primeiro, novo_nt])
                    self.glc[nt] = novas_prods_nt

                    # Cria as produções do novo estado: A' -> resto1 | resto2
                    prods_novo_nt = []
                    for p in prods:
                        resto = p[1:] if len(p) > 1 else ["ε"]
                        prods_novo_nt.append(resto)
                    
                    novos_nao_terminais[novo_nt] = prods_novo_nt
                    break # Quebra para reiniciar o laço com segurança

            # Adiciona os novos estados gerados no dicionário principal
            self.glc.update(novos_nao_terminais)
        print("Fatoração concluída.")
    def first_seq(self, rhs, first_dict):
        resultado = set()
        
        # Se a produção for apenas a palavra vazia
        if not rhs or rhs == ["ε"]:
            return {"ε"}

        for simbolo in rhs:
            f_simbolo = first_dict.get(simbolo, set())
            
            # Adiciona tudo do FIRST do símbolo atual, exceto o epsilon
            resultado |= (f_simbolo - {"ε"})
            
            # Se o símbolo atual não possui epsilon no seu FIRST, a propagação para por aqui
            if "ε" not in f_simbolo:
                break
        else:
            # todos os símbolos da sequência derivam epsilon. logo, a sequência inteira pode derivar epsilon.
            resultado.add("ε")
            
        return resultado

    def first(self, term):
        mudou = True
        first_dict = {t: {t} for t in term} # first de t = t
        for nterm in self.glc:
            first_dict.setdefault(nterm, set())
        while mudou:
            mudou = False
            for nterm, regras in self.glc.items():
                for rhs in regras:
                    f = self.first_seq(rhs, first_dict)
                    if not f <= first_dict[nterm]: # se f não é subconjunto de nterm
                        first_dict[nterm] |= f # união dos conjuntos
                        mudou = True
        self.first_sets = first_dict
        return self.first_sets

    def follow(self):
        simbolo_inicial = list(self.glc.keys())[0] # Puxa os dados da classe
        follow_sets = {nt: set() for nt in self.glc.keys()} # Inicializa o conjunto FOLLOW vazio para todos os Não-Terminais
        follow_sets[simbolo_inicial].add('$') # Coloca o cifrão '$' (fim de fita) no FOLLOW do símbolo inicial

        mudou = True
        while mudou:
            mudou = False
            for cabeca, regras in self.glc.items():
                for rhs in regras:
                    # Varre cada símbolo na produção para aplicar as regras em cima dos Não-Terminais
                    for i, simbolo in enumerate(rhs):
                        # Se o símbolo atual for um Não-Terminal (vamos chamá-lo de B)
                        if simbolo in self.glc: 
                            # beta é a sequência que vem imediatamente após B
                            beta = rhs[i+1:]
                            
                            if beta:
                                # Calcula o FIRST da sequência beta
                                f_beta = self.first_seq(beta, self.first_sets)
                            else:
                                # Se não tem nada depois de B, o beta é tratado como vazio
                                f_beta = {"ε"}

                            # Tudo que está em FIRST(beta), exceto ε, vai para FOLLOW(B)
                            novos_elementos = f_beta - {"ε"}
                            if not novos_elementos <= follow_sets[simbolo]:
                                follow_sets[simbolo] |= novos_elementos
                                mudou = True

                            #  Se beta deriva epsilon ou se não existe beta 
                            # então tudo em FOLLOW(cabeça) vai para FOLLOW(B)
                            if "ε" in f_beta:
                                if not follow_sets[cabeca] <= follow_sets[simbolo]:
                                    follow_sets[simbolo] |= follow_sets[cabeca]
                                    mudou = True
                                    
        self.follow_sets = follow_sets
        return self.follow_sets

    def carregar_tabela_slr(self):
        # """ GERADA POR IA
        # Carrega as regras de redução e a tabela ACTION / GOTO gerada pelo SLR Parser.
        # Os tokens em maiúsculo (TIPO_TOKEN e CLASSE_TOKEN) foram substituídos pelos 
        # rótulos originais do seu léxico: '<tipo>' e '<classe>'.
        # """
        # Regras (ID da regra: ("Não-Terminal", quantidade_de_itens_no_lado_direito))
        # O tamanho diz à pilha quantos estados ela deve desempilhar (pop) no Reduce.
        self.regras_reducao = { #PRODUÇÔES A SEREM REDUZIDAS
            1: ("<PROGRAMA>", 1), # <PROGRAMA> -> <DECLARACAO>
            2: ("<PROGRAMA>", 2), # <PROGRAMA> -> <PROGRAMA> <DECLARACAO>
            3: ("<DECLARACAO>", 5), # <DECLARACAO> -> definir variavel como tipo string
            4: ("<DECLARACAO>", 5)  # <DECLARACAO> -> <tipo> variavel = new <classe>
        }

        # Tabela ACTION: (estado_atual, token_lido) -> 'sX' (shift), 'rX' (reduce), 'acc' (accept)
        self.tabela_action = {
            (0, 'definir'): 's3', (0, '<tipo>'): 's4',
            (1, '$'): 'acc', (1, 'definir'): 's3', (1, '<tipo>'): 's4',
            (2, '$'): 'r1', (2, 'definir'): 'r1', (2, '<tipo>'): 'r1',
            (3, 'variavel'): 's6',
            (4, 'variavel'): 's7',
            (5, '$'): 'r2', (5, 'definir'): 'r2', (5, '<tipo>'): 'r2',
            (6, 'como'): 's8',
            (7, '='): 's9',
            (8, 'tipo'): 's10',
            (9, 'new'): 's11',
            (10, 'string'): 's12',
            (11, '<classe>'): 's13',
            (12, '$'): 'r3', (12, 'definir'): 'r3', (12, '<tipo>'): 'r3',
            (13, '$'): 'r4', (13, 'definir'): 'r4', (13, '<tipo>'): 'r4'
        }

        # Tabela GOTO: (estado_atual, Nao_Terminal) -> proximo_estado
        self.tabela_goto = {
            (0, '<PROGRAMA>'): 1,
            (0, '<DECLARACAO>'): 2,
            (1, '<DECLARACAO>'): 5
        }

    def executar_parser(self):
        #Algoritmo principal do autômato de pilha 
        #Consome a fita de saída do Léxico baseando-se na tabela SLR gerada no código acima
        print("\nIniciando Pilha de Análise Sintática...")
        self.carregar_tabela_slr()
        
        pilha = [0] # O estado inicial do autômato é sempre 0
        fita = self.fita.copy()
        fita.append('$') # Adiciona o marcador de fim de arquivo
        ponteiro = 0
        
        while True:
            estado_atual = pilha[-1] # LÊ O TOPO DA PILHA
            token_atual = fita[ponteiro]
            
            # Busca a ação na tabela (ACTION)
            acao = self.tabela_action.get((estado_atual, token_atual))
            
            if acao is None:
                # Disparo de Erro Sintático
                print(f"\n[ERRO SINTÁTICO] Token inesperado '{token_atual}' encontrado.")
                print(f"Estado da pilha: {pilha}")
                print(f"Fita restante: {fita[ponteiro:]}")
                return False
                
            if acao.startswith('s'):
                # Ação: SHIFT (Empilhar)
                proximo_estado = int(acao[1:]) #EMPILHA
                pilha.append(proximo_estado) # Empilha apenas on úmero do estado
                ponteiro += 1 # Avança o leitor na fita
                
            elif acao.startswith('r'):
                # Ação: REDUCE (Reduzir regra)
                num_regra = int(acao[1:])
                nao_terminal, tamanho_pop = self.regras_reducao[num_regra]
                
                # Desempilha N estados correspondentes ao corpo da regra
                for _ in range(tamanho_pop):
                    pilha.pop()
                    
                # Olha para o novo topo da pilha e consulta a tabela GOTO
                topo_atual = pilha[-1]  # LÊ O TOPO DA PILHA
                estado_goto = self.tabela_goto.get((topo_atual, nao_terminal))
                
                if estado_goto is None:
                    print(f"\n[ERRO FATAL SINTÁTICO] GOTO não encontrado para estado {topo_atual} e {nao_terminal}")
                    return False
                    
                # Empilha o estado de transição
                pilha.append(estado_goto)
                # OBS: Em um Reduce, o ponteiro da fita NÃO avança!
                
            elif acao == 'acc':
                # Ação: ACCEPT
                print("\n[SUCESSO] Análise Sintática concluída sem erros! A estrutura do código está validada.")
                return True


if __name__ == "__main__":
    print("Iniciando a fase léxica...")
    fita_saida, tabela_saida = executar_lexico()

    if fita_saida:
        print("Iniciando a fase sintática...")
        # sintatico = AnalisadorSintatico(fita_saida, tabela_saida)
        sintatico = AnalisadorSintatico(fita_saida, tabela_saida, caminho_glc="glc.txt")
        sintatico.eliminar_inuteis() # Tratamento de gramática
        sintatico.fatorar_glc() # Tratamento de gramática
        print("\n--- GLC Final Pós-Processamento ---")
        for nao_terminal, producoes in sintatico.glc.items():
            print(f"{nao_terminal} -> {producoes}")
        # print("Fita carregada: ", sintatico.fita)

        # First e Follow abaixo
        terminais = set()
        for producoes in sintatico.glc.values():
            for prod in producoes:
                for simbolo in prod:
                    if simbolo not in sintatico.glc and simbolo != "ε":
                        terminais.add(simbolo)
        sintatico.first(terminais)
        sintatico.follow()

        print(f"\nTerminais detectados: {terminais}")
        print("\n--- Conjuntos FIRST ---")
        for nt, f_set in sintatico.first_sets.items():
            print(f"FIRST({nt}) = {f_set}")
        print("\n--- Conjuntos FOLLOW ---")
        for nt, f_set in sintatico.follow_sets.items():
            print(f"FOLLOW({nt}) = {f_set}")

        sintatico.executar_parser()
