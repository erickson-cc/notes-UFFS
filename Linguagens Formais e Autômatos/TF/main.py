# Gerar um AFD livre de estados inalcançáveis e mortos
# Entrada: Arquivo com a relação de tokens e/ou GRs de uma linguagem
# Saída: AFD e mínimo sem a aplicação de classes de equivalência entre estados.

def iterarLinha(linha):
    linha = linha.strip() # quebra de linha
    if not linha:
        return

    if "::=" in linha:
        processarGramatica(linha)
    else
        processarToken(linha)
