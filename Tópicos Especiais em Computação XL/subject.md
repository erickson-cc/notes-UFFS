Tema: Projetos Práticos em Inteligência Artificial

Trabalho:Usar um modelo de IA para resolver um problema, os dados já estão coletados
Avaliação:
Apresentação Parcial dos Projetos (50%)
Apresentação Final (50%)


Fazer o trabalho sobre os sensores de fibra óptica nos tanques de óleo para encontrar a interface entre o óleo e a água.


--------MACHINE LEARNING--------
Aprendizado supervisionado:
    Além das variáveis do modelo, os resultados(rótulo) são fornecidos pelo programador.

Aprendizado não-supervisionado:
    Entrego só os dados e peço para a máquina para adivinhar. Não é fornecida a saída esperada.

Aprendizado por reforço:
    O próprio sistema vai se autoalimentando e vai aprendendo de acordo com as decisões que ele toma.


Em aprendizado supervisionado temos 2 tipos de problemas:
    Regressão:
        *Quando eu quero um número*
        Descobrir o preço de automóveis de acordo com os atributos fornecidos.

    Classificação:
        Temos um conjunto de imagens/modelos e um conjunto de classes.
        O sistema vai olhar para uma imagem/padrões e associá-la a uma das classes.

Previsão vs Predição:
    Na área de machine learning, muitas vezes esses 2 termos são sinônimos. A predição seria dar um conjunto de dados e, com base nesses dados, adivinhar a altura do nível de água/óleo. Já a previsão é utilizada num contexto mais amplo que usa um conjunto de predições, exemplo a previsão do tempo.


---------------------------------
Estrutura de Pastas:
.projeto_IA_GEX1090/
    .dados/
        .brutos/
        .processados/
    .notebooks/
    .resultado/
---------------------------------

Ciclo de Desenvolvimento:
    1. Coleta de Dados.
    2. Análise exploratória de Dados.
    3. Pré-processamento.
    4. Criação e Treinamento de Modelos.
    5. Avaliação dos Modelos
    6. Implantação do Modelo
    7. Monitoramento do modelo
    
# Coleta de Dados
    Fontes de dados: sensores, registros de processos, textos, imagens, áudios...

    Tipos de dados:
        - Estruturados: organizados em formato tabular (linhas, colunas)
        - Não Estruturados: sem formato definido(textos, vídeos, áudios, imagens)
        - Semi-Estruturados: possuem alguma organização, mas não totalmente estruturados (JSON, XML, logs de sistema)

# Análise Exploratória de Dados
    *O foco é diagnosticar a situação dos dados, antes do tratamento*
    Visualização inicial: histogramas, boxplots, séries temporais.
    Identificação de valores discrepantes(outliers) por meio de gráficos e medidas estatísticas.
    Identificação de valores ausentes: contagem de NaN.
    Identificação de desbalanceamento: histogramas de variáveis-alvo.
    Correlação e redundância : heatmap, scatterplots.

# Pré-processamento
    Ações corretivas para eventuais problemas identificados

    Tratamento de dados ausentes: remoção (se poucos) ou imputação (média, mediana, regressão, KNN...)
    
    Tratamento de valores discrepantes(outliers):
        - remoção (se claramente erro de medição)
        - substituição (winsorization, cap/floor)

    Codificação de variáveis categóricas:
        - One-hot encoding: transformar valores em números (A, B, C) -> B = [0, 1, 0]
            Ativa só aquele que vocẽ quer considerar, usado para previnir que o programa interprete que o 3 seja melhor que o 1.
        - Label encoding: quando há ordem natural (Ex: Graduação, Mestrado, Doutorado) -> 0, 1, 2

    Normalização/Padronização de atributos:
        Necessário quando as variáveis estão em escala muito diferentes
        Ex: comparar salário com idade, nível de óleo e comprimento de onda.
        MinMaxScaler, StandardScaler

    Redução de dimensionalidade (crianção e seleção de atributos / Feature Engineering / Selection)
        Agregação de atributos (médias móveis, diferenças, etc...)
        Transformações (log, polinômios, interações)
        Seleção de subconjuntos (Principal Component Analysis, Recursive Feature Elimination)
    
    Tratamento de desequilíbrios:
        Tratamento de sistemas enviesados
        Ex: Classe A tem 10K amostras e Classse B tem 100 Amostras.

# Perceptron
    Rede neural, Foi a precursora da IA, criado em 1958,
    Bias(viés)
    Machine Learning é basicamente uma média ponderada de várias entradas com várias saídas
    Função de ativação f(z) | "Relu" = max(0,z)
# Forward Pass
    x1 -- (N1) -> Z=w1x1+w2x2+b -> f(z) -> ŷ -> erro Loss
    x2 -- (N2) ´
    
    ŷ: estimativa

    x1norm = (x1-xmin)/(xmax-xmin)
    ŷorig=ymin+ŷnorm * (ymax-ymin)

    Amostra 1 (x1nom = 0.0, x2.nom = 0.0, ynom=0)
    z =0.2*0+0.3*0+0.1=0.1
    ŷnom=max(0,0.1)=0.1
    ŷorig = 50+0.1*20=52cm
    erro = ŷcm -ycm = 52-50
    MSE = 2^2 +(-2)^2 +(-3,5)^2 +(-1)^2+(-8)^2 = 17,06
    MSE_{norm} = 17,05/20^2

    ÉPOCA: calcular o forward pass de todas as amostras, calcular o gradiente, desnormalizar, calcular o erro, calcular a média do erros (MSE), normalizar a média dos erros (MSE_{norm})
# Khan
    
