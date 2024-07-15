#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* print_background(void* arg)
{
	pthread_detach(pthread_self());
	printf("Inside the thread\n");
	for(int i=0; i<5; i++)
	{
		printf("Counter number %d\n", i);
		usleep(500000);
	}
	pthread_exit(NULL);
}


int main(int argc, char **argv)
{
	pthread_t ptid;
	pthread_create(&ptid, NULL, &print_background, NULL);
	printf("New thread run\n");
	usleep(200000);
	printf("Wait to thread finishes\n");
	pthread_join(ptid, NULL);
	pthread_exit(NULL);	
	
	return 0;
}
