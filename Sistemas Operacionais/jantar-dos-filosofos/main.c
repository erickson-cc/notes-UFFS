// mutex, semaforos e thread
// cada filósofo vai utilizar uma thread
// o estado de cada semáforo do filosofo vai começar com 0
// índice 0 é semáforo do filosofo 0, e assim por diante
//
// inicializar as 5 threads
// passar o argumento o identificador do filosofo

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>			
#include <fcntl.h> 


void *mythread(void *data);

#define N 5 // number of threads
#define TRUE 1
#define TAKE_FORKS "has taken a fork\n"
#define PUT_FORKS "is putting forks\n"
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N 
sem_t mutex; // Semáforo real
sem_t s[N]; //array de threads
void think(int i){
	printf("Filósofo %d está pensando\n", i);
	sleep(rand() % 3+1); // define	um tempo randomico para dormir
}
void take_forks(int i){
	printf(TAKE_FORKS);
	sem_wait(&mutex);//down
	state[i] = HUNGRY;
	printf("Filósof %d está faminto\n", i);
	test(i);
	sem_post(&mutex);//up
	sem_wait(&s[i]);
}
void eat(){
	printf("Filósofo %d está está comendo\n", i);
	sleep(rand() % 3+1);
}

void put_forks(i){
	printf(PUT_FORKS);
	sem_wait(&mutex);
	state[i] = THINKING;
	printf("Filósofo %d está colocando garfos\n", i);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void test(i){
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[i] = EATING;
		sem_post(&s[i]);
	}
}




pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;



void philosopher(int i){
	while(TRUE){
		think();
		take_forks(i);
		eat();
		put_forks(i);
	}
}


//void *philosopher_thread(void *data){
//	int i = *(int*)data;
//	free(data);
//	while(TRUE){
//		think(i);
//		take_forks(i);
//		eat(i);
//		put_forks(i);
//	}
//	return NULL;
//}


int main() {
	pthread_t tids[N]; // define as 5 threads
	int i=0;

	sem_init(&mutex, 0, 1); // inicializa o semáforo com valor 1

	for(i=0; i<N; i++) {	
	      int *j = malloc(sizeof(int));
	      *j = i;
	      pthread_create(&tids[i], NULL, mythread, (void *)j); // cria as thread
	}
	/* We will now wait for each thread to<\n>
	      * terminate */
	for(i=0; i<N; i++) {
	      pthread_join(tids[i], NULL);
	      printf("Thread id %ld returned\n", tids[i]);
	}
	return 1;
}

