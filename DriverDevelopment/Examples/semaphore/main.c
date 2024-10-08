#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
#include <time.h>
#include <pthread.h>

#include "device.h"

void* runDriver(void* arg)
{
	int cont = 0;
	semaphore *Semaphore = (semaphore*) arg;
	while(Semaphore->running != 0){
		if(Semaphore->currentProcess != NULL){
			printf("Dispatching process ...\n");
			usleep(5000000);
			Semaphore->signal(Semaphore);
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{

	char ans;
	int majorID = 1, minorID = 1;
	
	semaphore Semaphore;
	semaphoreInit (&Semaphore);
	device Device = {
		.majorID = majorID,
		.minorID = minorID,
		.Semaphore = Semaphore,
	};

	pthread_t ptid;
	pthread_create(&ptid, NULL, &runDriver, &Device.Semaphore);
	printf("Runing driver in background ...\n");

	printf ("1. Enter a new process\n");
	printf ("2. Free device\n");
	printf ("3. Unqueue a process\n");
	printf ("4. Print queue\n");
	printf ("5. Flush queue\n");
	printf ("6. Print device information\n");
	printf ("---------------\n");
	printf ("x. Exit\n");	

	while (ans != 'x'){
		printf("Enter an option: \n");
		scanf(" %c", &ans);
		switch (ans) {
			case '1':
				Device.Semaphore.wait(&Device.Semaphore);
				break;
			case '2':
				Device.Semaphore.signal(&Device.Semaphore);
				break;
			case '3':
				Device.Semaphore.Queue->unqueue(Semaphore.Queue);
				break;
			case '4':
				printQueue(Semaphore.Queue);
				break;
			case '5':
				Device.Semaphore.Queue->flush(Semaphore.Queue);
				break;
			case '6':
				printf ("Device information\n");
				printf ("Major ID: %d Minor ID: %d \n", Device.majorID, Device.minorID);
				printf ("Current PID: %d \n", Device.Semaphore.getCurrentProcessID(&Device.Semaphore));
		}
	}
	
	Device.Semaphore.signal(&Device.Semaphore);
	Device.Semaphore.Queue->flush(Semaphore.Queue);
	Device.Semaphore.running = 0;

	pthread_join(ptid, NULL);
	pthread_exit(NULL);

	return 0;
}

