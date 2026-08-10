#include "circulo.h"
#include <iostream>
const double PI=3.1415;
circulo::circulo(double raio) {
	raio_=raio;

}
double circulo::calcula_perimetro() {
	return 2*PI*raio_;

}
void circulo::imprime_perimetro() {
	std::cout << "Perímetro do círculo: " << calcula_perimetro() << std::endl;

}

