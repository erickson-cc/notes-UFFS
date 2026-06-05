Etapa 1 (70% da nota):
    • construir as regras sintáticas da linguagem: GLC;
    • aplicar eliminação de inúteis e de fatoração na GLC;
    • Construção do conjunto de itens válidos, transições e first/follow
    • Construção da tabela de parsing SLR ou LALR
    ◦ SLR Parser Generator (http://jsmachines.sourceforge.net/machines/slr.html)
    ◦ GoldParser (http://www.goldparser.org/)
    • Implementação do algoritmo de mapeamento da tabela para reconhecimento sintático
    • Tabela de símbolos (suporte para as próximas etapas)
    • entrada: fita de saída do reconhecedor léxico;
    • saída: aceite ou mensagem(ns) de erro(s) sintático(s);
    • adicionar informações na tabela de símbolos para uso nas etapas subsequentes (a definir em
    cada projeto).
Etapa 2 (10% da nota):
    • definir uma característica semântica cujas informações adicionadas na TS sejam suficiêntes para
    a análise;
    • Adicionar informações na TS utilizando ações semânticas (procedimentos) no reconhecedor
    sintático (Esquema de Tradução);
    • implementar a análise semântica da característica especificada;
    • saída: aceite ou mensagem(ns) de erro(s) semântico(s);
Etapa 3 (10% da nota):
    • cada redução de uma produção (reconhecimento de uma estrutura sintática) é seguida de uma
    chamada a uma ação que gera o correspondente trecho de código intermediário com os
    respectivos rótulos dos identificadores, constantes, etc.
    • basta aplicar a geração de código intermediário para uma das regras sintáticas (demonstração);
    • saída: código intermediário;
Etapa 4 (10% da nota):
    • aplicar uma estratégia de otimização de código sobre o código intermediário gerado na etapa
    anterior
    • entrada: código intermediário
    • saída: código intermediário otimizado
