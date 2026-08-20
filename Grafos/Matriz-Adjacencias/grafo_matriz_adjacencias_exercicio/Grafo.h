//#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Aresta.h"

class Grafo {
	public:
// Constroi o graph com um numro de vert e sem arestas
		Grafo(int num_vertices);
		int num_vertices();
		int num_arestas();

		bool tem_aresta(Aresta e);

		void insere_aresta(Aresta e);
		void remove_aresta(Aresta e);

		void imprime();
	private:
		//int **matriz_adj;
		std::vector<std::vector<int>> matriz_adj_;
		int num_vertices_;
		int num_arestas_;
};

#endif
