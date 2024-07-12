#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "queue.h"

#define RESOURCES 0

typedef struct semaphore {
	int counter;
	struct process *currentProcess;
	struct process* (*newProcess)(void);
	queue *Queue;

	void (*wait) (struct semaphore*);
	void (*signal) (struct semaphore*);
	int (*getCurrentProcessID) (struct semaphore*);
} semaphore;

void wait (semaphore* Semaphore) {
	struct process *Process = Semaphore->newProcess();
	if (Semaphore->counter < 0) {
		printf ("Device busy with PID: %d ", Semaphore->currentProcess->id);
		printf ("Please wait ...\n");
		usleep (1000000);
		Semaphore->Queue->inqueue(Semaphore->Queue, Process);
	} else {
		printf("Assigning ...\n");
		Semaphore->currentProcess = Process;
	}
	Semaphore->counter--;
}

void signal (semaphore *Semaphore) {
	printf ("Freeing ...\n");
	free(Semaphore->currentProcess);
	if (Semaphore->Queue->head != NULL) {
		Semaphore->currentProcess = Semaphore->Queue->unqueue(Semaphore->Queue);
			//Semaphore->Queue->head->processp;
		//Semaphore->Queue->unqueue(Semaphore->Queue);
	} else {
		Semaphore->currentProcess = NULL;
	}
	Semaphore->counter++;
}

struct process *newProcess(void) {
	srand(time(NULL));
	int id = rand();
	struct process *Process = (struct process*)malloc(sizeof(struct process));
	Process->id = id;
	//printf("PUID: %d\n", Process->id);
	return Process;
}

int getCurrentProcessID(semaphore *Semaphore) {
	if (Semaphore->currentProcess == NULL){
		return -1;
	} else {
		return Semaphore->currentProcess->id;
	}
} 

void semaphoreInit (semaphore *Semaphore) {
	queue *Queue = (queue*) malloc (sizeof(queue));
	Semaphore->counter = RESOURCES;
	Semaphore->currentProcess = NULL;
	Semaphore->Queue = Queue;
	queueInit (Queue);
	Semaphore->wait = wait;
	Semaphore->signal = signal;
	Semaphore->newProcess = newProcess;
	Semaphore->getCurrentProcessID = getCurrentProcessID;
}
