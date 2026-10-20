#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {
        Grafo g(7);
        g.insere_aresta(Aresta(0, 1, 1));
        g.insere_aresta(Aresta(0, 2, 3));
        g.insere_aresta(Aresta(0, 3, 4));
        g.insere_aresta(Aresta(0, 4, 2));
        g.insere_aresta(Aresta(0, 5, 4));

        g.insere_aresta(Aresta(1, 5, 2));
        g.insere_aresta(Aresta(2, 5, 2));
        g.insere_aresta(Aresta(3, 5, 4));
        g.insere_aresta(Aresta(4, 5, 5));
        g.insere_aresta(Aresta(5, 5, 7));
        g.imprime();


    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
