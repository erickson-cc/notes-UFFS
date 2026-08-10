#include "circulo.h"
#include "pilha.h"
#include <iostream>
#include <stack>

int main(){
	circulo circulo1(5);
	circulo circulo2(6);
	//std::stack<int> pilha;
	pilha pilha_inteiros;

	std::cout << "Calculando círculo 1" << std::endl;
	circulo1.imprime_perimetro();

	std::cout << "Calculando círculo 2" << std::endl;
	circulo2.imprime_perimetro();

	std::cout << "Empilhando dois valores (10, 14)" << std::endl;
	pilha_inteiros.empilhar(10);
	pilha_inteiros.empilhar(14);

	pilha_inteiros.imprimir();

	std::cout << "Desempilhando os elementos" << std::endl;
	int removido = pilha_inteiros.desempilhar();
	std::cout << "Valor removido: " << removido << std::endl;

	removido = pilha_inteiros.desempilhar();
	std::cout << "Valor removido: " << removido << std::endl;

	pilha_inteiros.imprimir();

	return 0;
}
