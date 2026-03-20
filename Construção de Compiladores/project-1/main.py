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



