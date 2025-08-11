/**** Lista Encadeada
 * Passo 1:
 * 	Alocar Espaço
 * Passo 2:
 * 	Colocar os valores no espaço alocado
 * 	NULLificar as variáveis ponteiras
 * Passo 3:
 * 	Encadear
*********************/
struct employee{
	int id;
	char name[TAM_NOME+1];
	double income;
	struct employee *next;
};
typedef struct employee Employee;

Employee *e;
Employee *first = NULL;
Employee *aux;

e = (Employee *) malloc(sizeof(Employee)); // Passo 1

e->id = 1;  // Passo 2
strcpy(e->name, "One"); // Passo 2
e->income = 1456.32; // Passo 2
e->next = NULL; // Passo 2
if(first == NULL){ // Passo 2
	first = e;
}else{// Passo 3 encadeamento
aux->next=e;
aux = e;
}

