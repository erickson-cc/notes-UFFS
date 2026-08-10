#include <stack>
class pilha {
	public:
		pilha();
		void empilhar(int valor);
		int desempilhar();
		int imprimir();

	private:
		std::stack<int> inteiros_;
};

