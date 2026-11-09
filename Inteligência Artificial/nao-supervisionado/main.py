import pandas as pd
import numpy as np
from sklearn.cluster import KMeans

# 1. Carregar os dados
df = pd.read_csv('MusicasJogosDataset_20232_20262.csv')

# Separar a coluna de nomes (índice 0) das características (colunas 1 em diante)
nomes = df.iloc[:, 0]
X = df.iloc[:, 1:]

# 2. Configurar e executar o K-Means
# Escolhi n_clusters=3 (ver justificativa abaixo) e n_init='auto' (ou 10) que é o padrão
kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)
kmeans.fit(X)

# 3. Armazenar a classe (cluster) e os centroides
labels = kmeans.labels_
centroides = kmeans.cluster_centers_

# Adicionar os grupos ao dataframe para facilitar a visualização
df['Grupo_KMeans'] = labels

# Exibir em qual grupo você caiu
meu_indice = nomes[nomes.str.contains("Erickson", case=False, na=False)].index[0]
print(f"Erickson está no Grupo: {labels[meu_indice]}")
