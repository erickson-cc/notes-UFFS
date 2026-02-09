#include "selectDB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para buscar os metadados da tabela em "table.dic"
int getTableMetadata(const char *tableName, TableMetadata *metadata) {
    FILE *file = fopen("table.dic", "r");
    if (!file) {
        perror("Erro ao abrir table.dic");
        return 0;
    }

    while (fscanf(file, "%d %20s %20s\n", &metadata->id, metadata->logicalName, metadata->physicalName) == 3) {
        if (strcmp(tableName, metadata->logicalName) == 0) {
            fclose(file);
            return 1; // Tabela encontrada
        }
    }

    fclose(file);
    return 0; // Tabela não encontrada
}

// Função para buscar o esquema dos atributos em "att.dic"
int getAttributeMetadata(int tableId, AttributeMetadata **metadata, int *count) {
    FILE *file = fopen("att.dic", "r");
    if (!file) {
        perror("Erro ao abrir att.dic");
        return 0;
    }

    *count = 0;
    int currentSize = 10; // Tamanho inicial
    *metadata = (AttributeMetadata *)malloc(sizeof(AttributeMetadata) * currentSize);
    if (!*metadata) {
        perror("Erro de alocacao de memoria");
        fclose(file);
        return 0;
    }

    AttributeMetadata temp;
    while (fscanf(file, "%d %20s %c %c %d\n", &temp.fileId, temp.attributeName, &temp.type, &temp.optional, &temp.size) == 5) {
        if (temp.fileId == tableId) {
            if (*count >= currentSize) {
                currentSize *= 2;
                *metadata = (AttributeMetadata *)realloc(*metadata, sizeof(AttributeMetadata) * currentSize);
                if (!*metadata) {
                    perror("Erro de realocacao de memoria");
                    fclose(file);
                    return 0;
                }
            }
            (*metadata)[*count] = temp;
            (*count)++;
        }
    }

    fclose(file);
    if (*count > 0) {
        // Redimensiona para o tamanho exato necessário
        *metadata = (AttributeMetadata *)realloc(*metadata, sizeof(AttributeMetadata) * (*count));
        return 1;
    } else {
        free(*metadata);
        *metadata = NULL;
        return 0;
    }
}

// Função auxiliar para imprimir um atributo com base no tipo e tamanho
void printAttribute(FILE *file, char type, int size) {
    char *buffer = (char *)malloc(size + 1);
    if (!buffer) {
        perror("Erro de alocacao de memoria");
        return;
    }
    
    // Ler o campo do arquivo binário e ajustar o tipo de dado
    switch (type) {
        case 'I': {
            int intValue;
            fread(&intValue, size, 1, file);
            printf("%d ", intValue);
            break;
        }
        case 'S': {
            fread(buffer, size, 1, file);
            buffer[size] = '\0'; // Garantir que a string termine com null
            // Remover espaços em branco no final da string
            int i = size - 1;
            while (i >= 0 && buffer[i] == ' ') {
                buffer[i] = '\0';
                i--;
            }
            printf("%s ", buffer);
            break;
        }
        case 'D': {
            double doubleValue;
            fread(&doubleValue, size, 1, file);
            printf("%f ", doubleValue);
            break;
        }
        default:
            printf("Tipo de dado desconhecido. ");
            fseek(file, size, SEEK_CUR); // Pula o campo desconhecido
            break;
    }
    free(buffer);
}

// Função para ler e exibir os dados do arquivo físico
int readDataFile(const char *fileName, const AttributeMetadata *metadata, int count) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        perror("Erro ao abrir arquivo de dados");
        return 0;
    }

    // Imprime os nomes das colunas (atributos)
    for (int i = 0; i < count; i++) {
        printf("%s\t", metadata[i].attributeName);
    }
    printf("\n");

    // Lê os dados linha por linha
    while (!feof(file)) {
        long currentPos = ftell(file);
        
        // Verifica se a linha não está vazia ou corrompida
        int totalBytes = 0;
        for (int i = 0; i < count; i++) {
            totalBytes += metadata[i].size;
        }
        
        char *buffer = (char *)malloc(totalBytes);
        if (!buffer) {
            perror("Erro de alocacao de memoria");
            fclose(file);
            return 0;
        }
        
        size_t bytesRead = fread(buffer, 1, totalBytes, file);
        if (bytesRead < totalBytes) {
            // Fim do arquivo ou erro de leitura
            free(buffer);
            break; 
        }

        // Volta a posição do ponteiro para o início da linha
        fseek(file, currentPos, SEEK_SET);

        // Imprime os valores dos atributos
        for (int i = 0; i < count; i++) {
            printAttribute(file, metadata[i].type, metadata[i].size);
        }
        printf("\n");
    }

    fclose(file);
    return 1;
}
