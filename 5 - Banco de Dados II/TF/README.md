TF.1 -> encontrar bugs
TF.2 -> resolver bugs dos outros grupos
TF.3 -> implementar algo novo no uffsdb


instalar yacc e lex
os tokens estao em 'Fonte/interface/yacc.y'

Quando criarmos a regra, inserir no 'lex.l'
o lex vai ler os tokens e retornar a interpretação deste. exemplo:
    (?i:WHERE)						return WHERE;

Declarar o token, iniciar ele e iniciar uma produção/projeção(?).
o parser traz as funções setMode e resetQuery

todo mundo vai ter um .h e um .c

#ifndef X  // Evita que X não seja incluído 2 vezes
    // se o X não está incluído
    #include ______
    #define X
#endif

macros.h define várias variáveis fixas
