struct process {
	int id;
};

typedef struct node {
	struct process *processp;
	void *nextNode;
} node;

typedef struct queue {
	node *head;
	node *tail;
	struct process* (*unqueue)(struct queue*);
	void (*inqueue)(struct queue*, struct process *Process);
	void (*flush)(struct queue*);
} queue;

void inqueue (queue *nQueue, struct process *Process) {

	node *Node = (node*) malloc (sizeof(node));
	Node->processp = Process;
	Node->nextNode = NULL;

	if (nQueue->head == NULL) {
		nQueue->head = Node;
		nQueue->tail = Node;		
	} else {
		nQueue->tail->nextNode = Node;
		nQueue->tail = Node;
	}
}

struct process *unqueue (queue *nQueue) {
	if (nQueue->head != NULL){
		node *nNode = nQueue->head->nextNode;
		struct process *hProcess = nQueue->head->processp;
		free(nQueue->head);
		nQueue->head = nNode;
		return hProcess;
	} else {
		printf ("Queue Empty\n");
		return NULL;
	}
}

void flushQueue (queue *nQueue) {
	while (nQueue->head != NULL){
		nQueue->unqueue(nQueue);
	}
	printf ("Queue Flushed\n");

}

void printQueue (queue *nQueue) {
	node *nNode = nQueue->head;
	if (nNode != NULL){
		printf ("HEAD -> ");
		do {
			printf ("(%d) -> ", nNode->processp->id);
			nNode = nNode->nextNode;
		} while (nNode != NULL);
		printf("TAIL\n");
	} else {
		printf ("Queue Empty\n");
	}
}

void queueInit (queue *Queue) {
	Queue->head = NULL;
	Queue->tail = NULL;
	Queue->unqueue = unqueue;
	Queue->inqueue = inqueue;
	Queue->flush = flushQueue;
}
