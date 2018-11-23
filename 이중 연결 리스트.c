#include< stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int element;

typedef struct ListNode {
	struct ListNode *rlink;
	element data;
	struct ListNode * llink;
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

	if (list->head == NULL) {
		NewNode->rlink = NULL;
		NewNode->llink = NULL;
		list->head = NewNode;
	}
	else {
		NewNode->rlink = pPre->rlink;
		pPre->rlink = NewNode;
		NewNode->llink = pPre;
		if (NewNode->rlink != NULL)
			NewNode->rlink->llink = NewNode;
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
		else temp = temp->rlink;
	}

	return temp;
}

ListNode* SearchNumberList(List *list, element key) {
	ListNode *temp;

	temp = list->head;

	while (temp != NULL&&temp->rlink != NULL) {
		if (temp->data < key&&temp->rlink->data>key) {
			return temp;
		}
		else temp = temp->rlink;
	}

	return temp;
}

void RemoveNode(List *list, element data) {
	ListNode *pre;
	ListNode *old = SearchList(list, data);

	if (list->head == NULL) {
		printf("리스트가 비었습니다.");
		return;
	}

	else if (old == NULL) return;
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
		list->count--;
	}

}


void DestroyList(List *list) {
	ListNode *p;
	while (list->head != NULL) {
		p = list->head;
		list->head = list->head->rlink;
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
		else temp = temp->rlink;
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
		p = p->rlink;
		if (p != NULL) printf(",");
	}
	printf("\n");
}

int main() {
	int n = 0;
	int data;
	List *list = CreateList();
	ListNode *Pre = NULL;
	ListNode *temp = NULL;


	while (n != 3) {
		printf("In(0), Search(1), Out(2), Exit(3): ");
		scanf_s("%d", &n);
		if (n == 0) {
			printf("입력: ");
			scanf_s("%d", &data);
			Pre = SearchNumberList(list, data);
			_insertList(list, Pre, data);

		}

		if (n == 1) {
			printf("찾기: ");
			scanf_s("%d", &data);
			temp = SearchList(list, data);
			if (temp == NULL) printf("%d는 없습니다.", data);
			else printf("%d는 있습니다.", data);
		}

		if (n == 2) {
			printf("출력: ");
			scanf_s("%d", &data);
			RemoveNode(list, data);
			printf("%d는 제거되었습니다.", data);
		}

		printList(list);
	}


	return 0;
}