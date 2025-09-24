<h1>Modelos</h1>

O modelo random forest é um modelo *supervisionado* e *não-paramétrico*

Modelo paramétrico/parametrizado acontece quando eu já sei qual é o modelo de curva que ele me pertence.

Tipos de regressão:
- Regressão Linear: O tipo mais básico, que assume uma relação de linha reta entre as variáveis.

- Regressão Polinomial: Para problemas onde a relação não é uma linha reta, mas uma curva.

- Regressões Regularizadas (como Ridge e Lasso): Variações da regressão linear, usadas para lidar com o overfitting e melhorar o desempenho do modelo.


Árvore de decisão:
    A árvore vai dividindo os dados em nós para manter uma média apenas de dados correspondentes àquele nó de acordo com as características dos dados daquele nó.
    Os nós internos são so tomadores de decisão, e os nós folhas são as decisões. O nó raiz é o nó que vai conseguir olhar para todos os conjuntos de dados e decidir o que vai para a esquerda e o que vai para a direita; o nome desse limite de decisão é o threshold.

Altura ideal: log_2{n}
Número recomendado de amostras por nó: 20
O MSE_r é o MSE reduction
O MSE_w é o MSE weight


Sensores| 1550.1 | 1550.1 | 1550.2 | 1550.2 | 1550.2 | 1550.3 | 1550.3 | 1550.4 | 1550.4 | 1550.6 |
Nível   | 50 | 50 | 50 | 55 | 50 | 55 | 50 | 55 | 60 | 60 |

média da raiz = 53.5
n = 10

    1550.1
    1550.2
    1550.3
    1550.4
    1550.6
    Calcular os threshold de acordo com os valores y
        t1 = 1550.15
        t2 = 1550.25
        t3 = 1550.35
        t4 = 1550.5
    $$MSE = \dfrac{1}{n} \sum (y_1 - \overline{y})^2$$

    $$MSE = (60-53,5)^2 = 15,25$$


## t1
Nó raiz = 1550,15
    L=[50,50]
        ML = 50
            MSE_L = 0
    R=[50,55,50,55,50,55,60,60]
        MR = 54,375
            MSE_R = 15.234
    $$MSE_w = \dfrac{2*0+8*15,234}{10} = 12,184$$

O MSE_w é o MSE ponderado para essa árvore, note que 12,184 é mais preciso que 15,25

$$MSE_r = MSE_{root}-MSE_{split}$$
    MSE_r = 15,25-12,18 = 3,07

Agora precisamos testar o t2 e o t3 e o t4 para encontraro  melhor MSE_w
## t2
Nó raiz = 1550,25
    L=[50,50,50,55,50]
        ML = 51
            MSE_L = 4
    R=[55,50,55,60,60]
        MR = 56
            MSE_R = 14
    $$MSE_w = \dfrac{5*4+5*14}{10} = 9$$

O MSE_w é o MSE ponderado para essa árvore, note que 9 é mais preciso que 12,184
MSE_R
    MSE_r = 15,25-9 = 6,25

Agora precisamos testar o t3 e o t4 para encontraro  melhor MSE_w
## t3
Nó raiz = 1550,35
    L=[50,50,50,55,50,55,50]
        ML = 51,42
            MSE_L = 5,09
    R=[55,60,60]
        MR = 58,33
            MSE_R = 5,56
    $$MSE_w = \dfrac{5,09*7+5,56*3}{10} = 5,231$$
    MSE_r = 15,25-5,231 = 10,02
    **Para ir para a raiz, é preferível o maior MSE_r ou o menor MSE_w**

Agora precisamos testar o t4 para encontrar o melhor MSE_w
## t4
Nó raiz = 1550,5
    L=[50,50,50,55,50,55,50,55,60]
        ML = 52,78
            MSE_L = 11,73
    R=[60]
        MR = 60
            MSE_R = 0
    $$MSE_w = \dfrac{0*1+11,73*9}{10} = 10,557$$
    MSE_r = 15,25-10,557 = 4,69

Analisando os resultados, escolhemos o t3 para ser a raiz de nossa árvore de decisão


Agora, vamos fazer uma análise com os valores dos sensores da esquerda e da direita, separadamente

Sensores| 1550.1 | 1550.1 | 1550.2 | 1550.2 | 1550.2 | 1550.3 | 1550.3 |
Nível   | 50 | 50 | 50 | 55 | 50 | 55 | 50 |

    1550.1
    1550.2
    1550.3
        t1 = 1550.15
        t2 = 1550.25
        TERMINAR ESSA TAREFA
