#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>      
#include <fcntl.h> 

void *mythread(void *data);
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
#define N 3 // number of threads
sem_t s[N]; // Semáforo
#define MAX_GLOBAL_COUNTER 36

int GLOBAL_COUNTER; // Variável global a ser incrementada pelasa threads

int main(void) {

	GLOBAL_COUNTER = 0;
	
	pthread_t tids[N];
	sem_init(&s[0], 0, 1); // inicializa o semáforo com valor 1
	sem_init(&s[1], 0, 0); // inicializa o semáforo com valor 0
	sem_init(&s[2], 0, 0); // inicializa o semáforo com valor 0
			       // j

	int i;
	for(i=0; i<N; i++) { // Loop para criar as threads
		int *j = malloc(sizeof(int));
		*j = i;
		pthread_create(&tids[i], NULL, mythread, (void *)j); // Cria uma thread(&tids[i] é o identificador da thread)
	}
	/* We will now wait for each thread to<\n>
	* terminate */
	for(i=0; i<N; i++) {
		pthread_join(tids[i], NULL);
		printf("Thread id %ld returned\n", tids[i]);
	}
	return(1);
}


void *mythread(void *data) {
	int ID;
	ID = *((int *) data);
	int NEXT_ID;
	NEXT_ID = (ID+1)%N; //0->1->2->0...

	while(1){ //while(true){
		sem_wait(&s[ID]); // operação DOWN
		pthread_mutex_lock(&count_mutex); // lock no mutex

		if (GLOBAL_COUNTER >= MAX_GLOBAL_COUNTER){
			pthread_mutex_unlock(&count_mutex); // unlock no mutex
			sem_post(&s[NEXT_ID]);
			free(data);
			pthread_exit(NULL);
		}
		GLOBAL_COUNTER++;
		printf("\n Sou a thread %d e eu incrementei o contador para %d \n", ID, GLOBAL_COUNTER);
		pthread_mutex_unlock(&count_mutex); // unlock no mutex
		sem_post(&s[NEXT_ID]);
		sleep(1); // Dormir por 1 segundo
		/* We can return a pointer. Whatever pointer
		* we return can later be retrieved using the
		* pthread_join function */
	}

}
