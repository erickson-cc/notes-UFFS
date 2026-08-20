#include "Grafo.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

int main() {
	try {
		Grafo g(10);
		Aresta e(1, 3);
		g.tem_aresta(e);
		cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		g.insere_aresta(e);
		g.insere_aresta(e);
		g.insere_aresta(e);
		cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		g.remove_aresta(e);
		cout << "Tem Aresta (" << e.v1 << " com " << e.v2 <<"): " << g.tem_aresta(e) << "\n";
		g.insere_aresta(e);
		
		g.insere_aresta(Aresta(1,5));
		cout << "Tem Aresta (1 com 5): " << g.tem_aresta(Aresta(1,5)) << "\n";

		g.imprime();
	}
	catch (const exception &e) {
		cerr << "exception:: " << e.what() << "\n";
	}

}
