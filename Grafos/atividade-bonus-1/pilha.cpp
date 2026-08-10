#include "pilha.h"
#include <iostream>

pilha::pilha() {
	// COnstrutor não faz nada
}

void pilha::empilhar(int valor){
	inteiros_.push(valor);
}

int pilha::desempilhar(){
	if(inteiros_.empty()){
		std::cout << "Erro: a pilha já está vazia." << std::endl;
		return -1;
	}

	int valor = inteiros_.top();
	inteiros_.pop();
	return valor;
}

int pilha::imprimir(){
	if(inteiros_.empty()){
		std::cout << "Erro: a pilha está vazia." << std::endl;
		return -1;
	}

	std::stack<int> copia = inteiros_;
	std::cout << "Conteúdo da pilha:" << std::endl;

	while(!copia.empty()) {
		std::cout << copia.top() << std::endl;
		copia.pop(); // Vai popando e imprimindo até esvaziar
	}
	return 0;
}
