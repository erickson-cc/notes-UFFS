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
#include <errno.h>



#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define N 5 // number of threads
#define TRUE 1
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N 
sem_t mutex; // Semáforo real
sem_t s[N]; //array de threads
int state[N];
void *philosopher(void *data);
void take_forks(int i);
void put_forks(int i);
void test(int i);

void think(int i){
	printf("Philosopher %d is thinking\n", i);
	sleep(rand() % 3+1); // define	um tempo randomico para dormir
}
void take_forks(int i){
	printf("Philosofer %d has taken a fork\n",i);
	sem_wait(&mutex);//down
	state[i] = HUNGRY;
	printf("Philosopher %d is hungry\n", i);
	test(i);
	sem_post(&mutex);//up
	sem_wait(&s[i]);
}

void put_forks(int i){
	printf("Philosofer %d has taken a fork\n",i);
	sem_wait(&mutex);
	state[i] = THINKING;
	printf("Philosopher %d is putting forks\n", i);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void test(int i){
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[i] = EATING;
		sem_post(&s[i]);
	}
}




//pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;



void *philosopher(void *data){
	int id = *((int *) data);
	while(1){
		printf("Philosopher nº %d is thinking\n",id);
		sleep(1);
		take_forks(id);
		sleep(1);
		printf("Philosopher nº %d is eating\n",id);
		put_forks(id);
	}
}

//void *philosopher_thread(void *data){
//	int i = *(int*)data;
//	free(data);
//	while(TRUE){
//		think(id);
//		take_forks(id);
//		eat(id);
//		put_forks(id);
//	}
//	return NULL;
//}


int main() {
	pthread_t tids[N]; // define as 5 threads
	int i=0;

	sem_init(&mutex, 0, 1); // inicializa o semáforo com valor 1

	for(i=0; i<N; i++) {	
		sem_init(&s[i],0,0);
		state[i]=THINKING;
	}
	for(i=0; i<N; i++) {	
	      int *j = malloc(sizeof(int));
	      *j = i;
	      printf("Creating philosopher %d\n", *j);
	      pthread_create(&tids[i], NULL, philosopher, (void *)j); // cria as thread
	}
	/* We will now wait for each thread to<\n>
	      * terminate */
	for(i=0; i<N; i++) {
	      pthread_join(tids[i], NULL);
	      printf("Thread id %ld returned\n", tids[i]);
	}

	return 1;
}

