A1
A2
MT: Avaliação Teórica
MP: Trabalhos Práticos
MT = (A1 + A2)/2
MP = (Média Trabalhos Satélites)*0.3 + (Trabalho Final)*0.7
MF = MT*0.6 + MP*0.4



# Arquivos de dados

Os arquivos organizados no formato de heap são adicionados como uma pilha (um atrás do outro), não existe ordem, e são acessados pela chave através de um scan (acaba varrendo todos os dados da estrutura)

A árvore B+ armazena os índices das tuplas de todo o banco.


# Índices

índice denso é o espaço que contem entradas com todas as chaves do arquivo de dados.

PK não contém duplicatas

# Hashing

Atributo vai ser usado para a localização do registro, o atributo é passado para uma função, a função calcula o número e esse número é a localização do registro.

A função de hashing 

o número esperado de chaves/buckets é o mesmo para os buckets

hashing estático (buckets não-nulos)

    Processo de hashing por linear probe hashing, criar uma tabela de hashing que atenda ao workload, inserir na tabela até acontecer uma colisão, colocar o item na próxima posição livre da tabela.

hashing dinâmico (crescem conforme a necessidade) {tipo extensível e tipo linear}

hashin extensível:
    use i bits b de saída pela função de hashing
    2 variáveis de controle (global e local)
    global indica o máximo de bits a considerar iniciando com 1 (máximo de buckets)
    local indica quantos bits o bucket considera (tamanho dos buckets)

# Stored Procedures
 
# Tablespace
    
