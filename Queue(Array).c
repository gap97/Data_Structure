#include<stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct {
	element *queue;
	int front, rear;
	int size;
}Queue;

Queue *createQueue() {
	Queue *Q;
	Q = (Queue*)malloc(sizeof(Queue));
	Q->front = -1;
	Q->rear = -1;

	return Q;
}

int isEmptyQueue(Queue *Q) {
	if (Q->front == Q->rear) {
		printf("Queue is empty");
		return 1;
	}
	else return 0;
}

int isFullQueue(Queue *Q) {
	if (Q->rear = Q->size - 1) {
		printf("Queue is full");
		return 1;
	}
	else return 0;
}

void enQueue(Queue *Q, element item) {
	if (isFullQueue(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(Queue *Q) {
	if (isEmptyQueue(Q)) return;
	else {
		Q->front++;
		return Q->queue[Q->front ];
	}
}

element peek(Queue *Q) {
	if (isEmptyQueue(Q)) return;
	else return Q->queue[Q->front + 1];

}

int main() {
	
	return 0;
}