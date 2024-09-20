criar um vetor count de 10 posições

fazer o counting dos dígitos que estão mais à direita de todos os elementos do vetor.

criar um vetor aux de len(soma acumulada)



23 14 1 15 7 33



0 1 2 3 4 5 6 7 8 9

0 1 0 2 1 1 0 1 0 0

0 1 1 3 4 5 5 6 6 6

criar vetor aux1 (o [n] é referente ao número do decimal de trás pra frente)

|_ _ _ _ _ _|

0 1 1 2 4 5 5 6 6 6

x x 33 x x x 



0 1 1 2 4 5 5 5 6 6

x x 33 x x 07



0 1 1 2 4 4 5 5 6 6

x x 33 x 15 07



0 0 1 2 4 4 5 5 6 6

1 x 33 x 15 07



0 0 1 2 3 4 5 5 6 6

1 x 33 14 15 07



0 0 1 1 3 4 5 5 6 6

01 23 33 14 15 07 -- aux1

Fazer o counting2 



0 1 2 3 4 5 6 7 8 9

2 2 1 1 0 0 0 0 0 0

2 4 5 6 0 0 0 0 0 0



fazer o aux2 e comparar com o aux 1 de trás para frente

x x x x x x



1 4 5 6 0 0 0 0 0 0

x 07 x x x x



1 3 5 6 0 0 0 0 0 0

x 07 x 15 x x



1 2 5 6 0 0 0 0 0 0

x 07 14 15 x x



1 2 5 5 0 0 0 0 0 0

x 07 14 15 x 33



1 2 4 5 0 0 0 0 0 0

x 07 14 15 23 33



0 2 4 5 0 0 0 0 0 0

01 07 14 15 23 33
