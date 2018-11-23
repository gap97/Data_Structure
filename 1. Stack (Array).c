#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* stack;
	int size;
	int top;
} Stack;

Stack *CreateStack(int size);
void Push(Stack *pStack, int item);
int Pop(Stack *pStack);
int Top(Stack *pStack);
void DestroyStack(Stack *pStack);
bool IsFullStack(Stack *pStack);
bool IsEmptyStack(Stack *pStack);
int CountStackItem(Stack *pStack);
void ClearStack(Stack *pStack);

int main() {
	int item;
	Stack *pStack;
	int n = 1;
	int size;

	printf("size: ");
	scanf_s("%d", &size, sizeof(size));

	pStack = CreateStack(size);

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
		if (n == 6) printf("%s\n", IsEmptyStack(pStack) ? "true" : "false");
		if (n == 7) printf("%d\n", CountStackItem(pStack));
		if (n == 8) ClearStack(pStack);
		if (n == 9) DestroyStack(pStack);
	}

	return;
	free(pStack);
}



Stack *CreateStack(int size) {

	Stack *pStack = (Stack *)malloc(sizeof(Stack));

	if (pStack == NULL)
		return NULL;

	pStack->stack = (int *)malloc(size * sizeof(int));

	if (pStack->stack == NULL)
	{
		free(pStack); return NULL;
	}

	pStack->size = size;

	pStack->top = -1;

	return pStack;
}

void Push(Stack *pStack, int item) {
	if (pStack->top == pStack->size - 1) {
		printf("This Stack is full\n");
		return;
	}

	pStack->stack[++pStack->top] = item;
}

int Pop(Stack *pStack) {
	if (pStack->top <= -1) {
		printf("This Stack is empty\n");
		return 0;
	}
	else return pStack->stack[pStack->top--];
}

int Top(Stack *pStack) {
	return pStack->stack[pStack->top];
}

void DestroyStack(Stack *pStack) {
	free(pStack);
	printf("Stack is destroyed\n");
	return;
}

bool IsFullStack(Stack *pStack) {
	if (pStack->top == pStack->size - 1)
		return true;

	else return false;
}

bool IsEmptyStack(Stack *pStack) {
	if (pStack->top == -1)
		return true;

	else return false;

}

int CountStackItem(Stack *pStack) {
	return pStack->top + 1;
}

void ClearStack(Stack *pStack) {
	pStack = NULL;
	return;
}