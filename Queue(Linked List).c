#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct QNode {
	char data;
	struct QNode *link;
}QNode;

typedef struct {
	QNode *front, *rear;
}Queue;

Queue *CreateLinkedQueue() {
	Queue *Q;
	Q = (Queue*)malloc(sizeof(Queue));
	Q->rear = NULL;
	Q->front = NULL;
	return Q;
}

bool isEmpty(Queue *Q) {
	if (Q->front == NULL) {
		printf("Queue is empty");
		return true;
	}
	else return 0;
}

void enQueue(Queue *Q, char item) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if (Q->front == NULL) {
		Q->front = newNode;
		Q->rear = newNode;
	}

	else {
		Q->rear->link = newNode;
		Q->rear = newNode;
	}

}

char deQueue(Queue *Q) {
	QNode *Pre = Q->front;
	char item;

	if (isEmpty(Q)) return 0;
	else {
		item = Pre->data;
		Q->front = Q->front->link;
		if (Q->front == NULL) Q->rear == NULL;
		free(Pre);
		return item;
	}
}

char peek(Queue *Q) {
	char item;
	if (isEmpty(Q)) return 0;

	else {
		item = Q->front->data;
		return item;
	}
}

void printfQueue(Queue *Q) {
	QNode *tmp = Q->front;
	printf("Queue:");

	printf("(");
	while (tmp) {
		printf("%c", tmp->data);
		tmp=tmp->link;
	}
	printf(")");
}

int main() {


	return 0;
}