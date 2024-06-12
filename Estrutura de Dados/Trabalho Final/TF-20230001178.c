#include <stdio.h>
// struct Task(id,description,deadline,state=0) 
// 		state = 0 (ATIVA)
// 		state = 1 (CONCLUÍDA)
// task addTask
// task showTasks(any, state=1, state=0)
// 		sort 1-> state = 0
// 		if state = 0 -> deadline(0,inf)
// task concludeTask
// task popTask
// void mainMenu 
//
// BONUS - TAD .h & .c // binary tree (id)
void mainMenu(){
	int command;
	printf("-------Sistema de Gerenciamento de Tarevas v1.0-----------\n");
	printf("Digite o número:\n");
	printf("1 - Adicionar Tarefa\n");
	printf("2 - Visualizar Tarefas\n");
	printf("3 - Finalizar Tarefa\n");
	printf("4 - Remover Tarefa\n");
	printf("0 - Encerrar Programa\n");

}
int main(){
	mainMenu();
	return 0;
}
