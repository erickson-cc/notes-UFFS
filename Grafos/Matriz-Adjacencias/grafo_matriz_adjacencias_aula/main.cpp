#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo g(6);

        Aresta e(1, 3);
        cout << "Tem aresta (1,3): " << g.tem_aresta(e) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:

        g.insere_aresta(Aresta(1, 3));

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1: 3
        // 2:
        // 3: 1
        // ...
        // 5:

        g.remove_aresta(Aresta(1, 3));
        g.remove_aresta(Aresta(2, 5));

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
