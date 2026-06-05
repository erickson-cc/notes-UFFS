#from analex import analisadorLex, afd, finais_afd, rotulos_afd
from analex import executar_lexico

# Como a memória do seu programa deve ficar após ler a GLC:
class AnalisadorSintatico:
    def __init__(self, fita_tokens, tabela_simbolos):
        self.fita = fita_tokens
        self.tabela_simbolos = tabela_simbolos
        self.glc = {
                "PROGRAMA": [["DECLARACAO"], ["PROGRAMA", "DECLARACAO"]],
                "DECLARACAO": [["definir", "variavel", "como", "tipo", "string"]]
                }
        print(f"Analisador sintático iniciado com uma fita de {len(self.fita)} tokens.")
        print(f"Gramática carregada com {len(self.glc)} regras não-terminais.")


if __name__ == "__main__":
    print("Iniciando a fase léxica...")
    fita_saida, tabela_saida = executar_lexico()

    if fita_saida:
        print("Iniciando a fase sintática...")
        sintatico = AnalisadorSintatico(fita_saida, tabela_saida)
        print("Fita carregada: ", sintatico.fita)
