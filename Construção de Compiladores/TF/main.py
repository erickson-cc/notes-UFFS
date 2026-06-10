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

if __name__ == "__main__":
    print("Iniciando a fase léxica...")
    fita_saida, tabela_saida = executar_lexico()

    if fita_saida:
        print("Iniciando a fase sintática...")
        sintatico = AnalisadorSintatico(fita_saida, tabela_saida)
        print("Fita carregada: ", sintatico.fita)
