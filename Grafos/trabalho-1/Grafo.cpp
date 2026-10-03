#include "Grafo.h"
#include <iostream>
#include "Aresta.h"
#include <queue>
#include <algorithm>

using namespace std;

Grafo::Grafo (int num_vertices){
	if (num_vertices <=0) {
		throw(invalid_argument("Erro no construtor Grafo(int): o número de vértices é inválido " + to_string(num_vertices)));
	}
	matriz_adj_.resize(num_vertices);
	for (int i=0; i<num_vertices; i++) {
		matriz_adj_[i].resize(num_vertices,0);
	}

	num_vertices_ = num_vertices;
	num_arestas_ = 0;
}

int Grafo:: num_vertices(){
	return num_vertices_;
}

int Grafo:: num_arestas(){
	return num_arestas_;
}

bool Grafo:: tem_aresta(Aresta e){
	if (matriz_adj_[e.v1][e.v2] != 0) {
		return true;
	}
	return false;
}

void Grafo:: insere_aresta(Aresta e){
	if ( !tem_aresta(e) && (e.v1!=e.v2) ){
		matriz_adj_[e.v1][e.v2] = 1;
		matriz_adj_[e.v2][e.v1] = 1;

		num_arestas_++;
	}
}
void Grafo:: remove_aresta(Aresta e){
	if ( tem_aresta(e) ){
		matriz_adj_[e.v1][e.v2] = 0;
		matriz_adj_[e.v2][e.v1] = 0;

		num_arestas_--;
	}
}

void Grafo:: imprime(){
	cout << "Grafo:\n";
	for(int v=0; v<num_vertices_;v++){
		cout << v << " : ";
		for (int u=0; u<num_vertices_;u++){
			if (tem_aresta(Aresta(v,u))){
					cout << u << " ";
					}
		}
		cout << "\n" ;
	}
}
bool Grafo::caminho(int v, int w, int marcado[], int nivel) {
	// Criei a variável nível
	for (int i=0;i<nivel;i++){
		cout << "--";
	}
	cout << "caminho(" << v << ", " << w << ")\n";

	if (v == w)
		return true;
	marcado[v] = 1;
	for (int u = 0; u < num_vertices_; u++)
		if (matriz_adj_[v][u] != 0)
			if (marcado[u] == 0)
				if (caminho(u, w, marcado, nivel+1)){// Chamei recursivamente com nivel+1
					return true;
				}
	return false;
}

vector<int> Grafo:: testeTTL(int raiz, int ttl){
	// Vamos usar um pair pra manter a raiz e o ttl um ao lado do outro
  queue<pair<int, int>> fila;
  vector<int> marcado(num_vertices_, 0);
  vector<int> expirados;
  vector<int> nao_alcancados;
  
	marcado[raiz] = 1;
  
  fila.push({raiz, ttl});
  
  while (!fila.empty()) {
  	// Como estamos usando pair, precisamos de .first e .second para pegar os valores (x, y)
    int w     = fila.front().first;
    int ttl_r = fila.front().second;
    
   
    fila.pop();
    
    //printf("%d\n", w);
    for (int u = 0; u < num_vertices_; u++){
      if (matriz_adj_[w][u] != 0){
	      if (marcado[u] == 0) {
		  marcado[u] = 1;
		  // Colocar o time to live - 1, ja que estamos indo mais fundo no grafo
		  fila.push({u, ttl_r - 1});

        }
      }
    }
    if(ttl_r < 0){
	    expirados.push_back(w);
    }
	for (int i = 0; i < num_vertices_; i++) {
		if (marcado[i] == 0) {
		    nao_alcancados.push_back(i);
        }
	}
    
  }

    for(int i = 0; i < num_vertices_; i++){
  	if(marcado[i] == 0 ){
		expirados.push_back(i);
    }
  }

	sort(expirados.begin(), expirados.end());
	return expirados;
}


