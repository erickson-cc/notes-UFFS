#include "Grafo.h"
#include "Aresta.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
  // N e um C (N é número de vértices e C é o número de conexões)
  int N, C, X, Y, O;
  
  std::cin >> N >> C;
  Grafo g(N);
  
  // C linhas com 2 inteiros X e Y (conexões do grafo)
  for(int i = 0; i < C; i++){
  	std::cin >> X >> Y;
  	g.insere_aresta(Aresta(X, Y));
  }
  
  std::cin>>O;
  
  // Quantos casos de testes temos
  for(int i = 0; i < O; i++){
  	// Ler duas variáveis, uma para o vértice que começa o envio da mensagem outro para o TTL
    int src, ttl;
    std::cin >> src >> ttl;
    std::vector<int> retorno = g.testeTTL(src, ttl);
    std::cout<<src<<" "<<ttl<<":";
    if(retorno.size() > 0){
	std::cout << " ";
    }
    else{
	std::cout << "\n";
    }

    for(int i = 0; i < retorno.size(); i++){
	if(i < retorno.size() - 1){
		std::cout<<retorno[i]<<" ";
	}
	else{
		std::cout<<retorno[i]<<"\n";
	}
    }
  }
}
