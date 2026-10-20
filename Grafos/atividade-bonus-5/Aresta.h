#ifndef ARESTA_H

#define ARESTA_H

#include <string>

class Aresta {
public:
    const int v1;
    const int v2;
    const int peso;

    Aresta(int v1, int v2, int peso);

    std::string to_string();
};

#endif /* ARESTA_H */
