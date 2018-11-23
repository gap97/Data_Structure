#include< stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode * link;
}ListNode;

typedef struct HeadNode {
	int count;
	ListNode *head;
}List;

List *CreateList() {
	List *NewList = (List*)malloc(sizeof(List));
	if (NewList == NULL) return NULL;

	NewList->count = 0;
	NewList->head = NULL;

	return NewList;
}

void _insertList(List *list, ListNode *pPre, element data) {
	ListNode *NewNode = (ListNode*)malloc(sizeof(ListNode));

	NewNode->data = data;

	if (pPre == NULL) {
		NewNode->link = list->head;
		list->head = NewNode;
	}
	else {
		NewNode->link = pPre->link;
		pPre->link = NewNode;
	}
	list->count++;
}

ListNode* SearchList(List *list, element key) {
	ListNode *temp;
	temp = list->head;
	while (temp != NULL) {
		if (temp->data == key) {
			return temp;
		}
		else temp = temp->link;
	}

	return temp;
}

void RemoveNode(List *list, element data) {
	ListNode *pre;
	ListNode *p = SearchList(list, data);

	if (list->head == NULL) {
		printf("리스트가 비었습니다.");
		return;
	}

	if (list->head->link == NULL) {
		free(list->head);
		list->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = list->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
		list->count--;
	}

}

void reverse(List *list) {
	ListNode *p;
	ListNode *q;
	ListNode *r;

	q = list->head;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	list->head = q;
}


void DestroyList(List *list) {
	ListNode *p;
	while (list->head != NULL) {
		p = list->head;
		list->head = list->head->link;
		free(p);
		p = NULL;
	}
}

ListNode * TraverseList(List *list, element fromWhere, element data) {
		ListNode *temp;
		temp = SearchList(list, fromWhere);
		while (temp != NULL) {
			if (temp->data == data) {
				return temp;
			}
			else temp = temp->link;
		}
		return temp;
}

int ListCount(List *list) {
	return list->count;
}

bool IsEmptyList(List *list) {
	if (list->count == 0)
		return true;
	else return false;
}

void printList(List *list) {
	ListNode *p;
	printf("List: ");
	p = list->head;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf("\n");
}

int main() {
	

	return 0;
}