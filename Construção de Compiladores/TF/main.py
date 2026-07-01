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
    def first_seq(rhs, first, terminais):
        resultado = set()
        
        # Se a produção for apenas a palavra vazia
        if not rhs or rhs == ["ε"]:
            return {"ε"}

        for simbolo in rhs:
            f_simbolo = first.get(simbolo, set())
            
            # Adiciona tudo do FIRST do símbolo atual, exceto o epsilon
            resultado |= (f_simbolo - {"ε"})
            
            # Se o símbolo atual não possui epsilon no seu FIRST, a propagação para por aqui
            if "ε" not in f_simbolo:
                break
        else:
            # todos os símbolos da sequência derivam epsilon. logo, a sequência inteira pode derivar epsilon.
            resultado.add("ε")
            
        return resultado
    def first(prod, term):
        mudou = True
        first = {t: {t} for t in term} # first de t = t
        for nterm in prod:
            first.setdefault(nterm, set())
        while mudou:
            for nterm, regras in prod.items():
                for rhs in regras:
                    f = first_da_sequencia(rhs, first, term)
                    if not f <= first[nterm]: # se f não é subconjunto de nterm
                        first[nterm] |= f # união dos conjuntos
                        mudou = True
                    else:
                        mudou = False
        return first


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
