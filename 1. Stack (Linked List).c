#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tStackNode { 
	int data; 
	struct tStackNode *next; 
} StackNode;

typedef struct { 
	int count; 
	StackNode *top; 
} Stack;

Stack *CreateStack();
void Push(Stack *pStack, int item);
int Pop(Stack *pStack);
int Top(Stack *pStack);
void DestroyStack(Stack *pStack);
bool IsEmptyStack(Stack *pStack);
int CountStackItem(Stack *pStack);
void ClearStack(Stack *pStack);

int main() {
	int item;
	Stack *pStack;
	int n = 1;

	pStack =CreateStack();
	
	while (n != 0) {
		

		printf("2:Push\t3:Pop\t4:Top\t6:IsEmptyStack\n7:CountStackItem\t8:ClearStack\t9:DestroyStack\t0:close\n");
		printf("n:");
		scanf_s("%d", &n);

		if (n == 2) {
			printf("number: ");
			scanf_s("%d", &item);
			Push(pStack, item);
		}

		if (n == 3) printf("%d\n", Pop(pStack));
		if (n == 4) printf("%d\n", Top(pStack));
		if (n == 6) printf("%s\n", IsEmptyStack(pStack) ? "true":"false");
		if (n == 7) printf("%d\n", CountStackItem(pStack));
		if (n == 8) ClearStack(pStack);
		if (n == 9) DestroyStack(pStack);
	}

	return;
	free(pStack);
}

Stack *CreateStack() {

	Stack *pStack = (Stack *)malloc(sizeof(Stack));
	if (pStack == NULL) return NULL; 
	pStack->count = 0; 
	pStack->top = NULL;
	return pStack;
}

void Push(Stack *pStack, int item) {
	StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode)); 
	if (pNewNode == NULL) 
		return;
	
	pNewNode->data = item; 
	pNewNode->next = pStack->top; 
	pStack->top = pNewNode; 
	pStack->count++;

}

int Pop(Stack *pStack) {

	int out;
	
	StackNode* temp;
	temp = pStack->top;
	out = pStack->top->data;
	pStack->top = pStack->top->next;

	free(temp);

	pStack->count--;

	return out;

}

int Top(Stack *pStack) {

	return pStack->top->data;

}

void DestroyStack(Stack *pStack) {
	
	free(pStack);
	printf("Stack is destroyed\n");
	
	return;
}

bool IsEmptyStack(Stack *pStack) {
	if (pStack->count == 0)
		return true;

	else return false;

}

int CountStackItem(Stack *pStack) {
	return pStack->count;
}

void ClearStack(Stack *pStack) {
	pStack = NULL;
	return;
}