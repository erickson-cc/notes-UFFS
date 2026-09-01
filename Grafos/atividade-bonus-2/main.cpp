#include "Grafo.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

int main() {
	try {
		Grafo g(10);
		//Aresta e(1, 3);
		//g.tem_aresta(e);
		//cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		//g.insere_aresta(e);
		//cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		//g.remove_aresta(e);
		//cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		//g.insere_aresta(e);
		
		g.insere_aresta(Aresta(0,1));
		g.insere_aresta(Aresta(0,2));
		g.insere_aresta(Aresta(0,5));
		g.insere_aresta(Aresta(2,3));
		g.insere_aresta(Aresta(2,4));
		g.insere_aresta(Aresta(2,5));
		g.insere_aresta(Aresta(3,4));
		g.insere_aresta(Aresta(3,5));

		g.imprime();

		cout << "\n\n";

		int marcado[10] = {0};
		// Testando com sucesso
		bool existe = g.caminho(1,4,marcado);
		cout << "Existe caminho (1,4): " << existe << "\n";

		cout << "\n\n";
		// Testando sem sucesso
		existe = g.caminho(1,9,marcado);
		cout << "Existe caminho (1,9): " << existe << "\n";
	}
	catch (const exception &e) {
		cerr << "exception:: " << e.what() << "\n";
	}

}
