#include "semaphore.h"

typedef struct device {
	int majorID;
	int minorID;
	semaphore Semaphore;
} device;

void deviceInit (device *Device) {
	//semaphore *Semaphore = (semaphore*) malloc (sizeof(semaphore));
	semaphore Semaphore;
	semaphoreInit (&Semaphore);
	Device->Semaphore = Semaphore;

}
