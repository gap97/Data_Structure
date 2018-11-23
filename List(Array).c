#include< stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int element;

typedef struct List {
	element *data;
	int size;
	int count;
}List;

bool IsEmptyList(List *list) {
	if (list->count == -1)
		return true;
	else return false;
}

bool IsFullList(List *list) {
	if (list->count == list->size - 1)
		return true;
	else return false;

}

List *CreateList(int size) {
	List *NewList = (List*)malloc(sizeof(List));

	if (NewList == NULL)
		return NULL;

	NewList->data = (element *)malloc((size + 1) * sizeof(element));

	if (NewList->data == NULL)
	{
		free(NewList); return NULL;
	}

	NewList->size = size;

	NewList->count = -1;

	return NewList;
}

void _insertList(List *list, int location, element data) {
	int i;

	if (IsFullList(list)) {
		printf("리스트가 꽉 찼습니다.\n");
		return;
	}

	for (i = list->size; i >= location; i--)
		list->data[i] = list->data[i - 1];
	list->data[location] = data;
	list->count++;
	return;
}

int SearchList(List *list, element key) {

	int i;

	for (i = 0; i < list->size; i++) {
		if (list->data[i] == key)
			return i;
	}

	return -1;
}


void RemoveNode(List *list, element data) {
	int location = SearchList(list, data);
	int i;

	if (location == -1) {
		printf("존재하지 않는 데이터입니다.");
		return;
	}

	for (i = location; i <= list->count - 1; i++)
		list->data[i] = list->data[i + 1];
	list->data[list->count] = 0;
	list->count--;
}

void DestroyList(List *list) {
	free(list);
	printf("List is destroyed\n");
	return;
}


void printList(List *list) {
	int i;
	printf("\n\n현재 list의 상태는 ");
	for (i = 0; i <= list->count; i++) printf(" %d", list->data[i]);
	printf("\n\n");
}

int main() {

	return 0;
}