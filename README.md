# Data Structure

## 0. 설명
C언어를 이용하여 구현한 Data Structure(Stack, List, Queue)입니다.


## 1. Stack
한 쪽 끝에서만 자료를 넣고 뺄 수 있는 LIFO(Last In First Out) 형식의 자료 구조로, LIFO(Last In First Out) 를 따릅니다. 즉, 가장 최근에 스택에 추가한 항목이 가장 먼저 제거될 항목입니다. 

### ▸ Array를 이용한 기본 structure는 다음과 같습니다.

typedef struct {

	int* stack;

	int size;
	
	int top;

} Stack;

### ▸ Linked List를 이용한 기본 structure는 다음과 같습니다.

typedef struct tStackNode { 

	int data; 
	
	struct tStackNode *next; 

} StackNode;

typedef struct { 

	int count; 
	
	StackNode *top; 

} Stack;

### ▸다음과 같은 연산을 포함합니다.
pop(Stack *pStack): 스택에서 가장 위에 있는 항목을 제거합니다.

push(item): item 하나를 스택의 가장 윗 부분에 추가합니다.

isEmpty(Stack *pStack): 스택이 비어 있을 때에 true를 반환합니다.

Top(Stack *pStack): 스택의 가장 윗 항목을 반환합니다.

DestroyStack(Stack *pStack): 스택을 삭제합니다.

IsFullStack(Stack *pStack): 스택이 가득 차 있는지를 검사합니다.

IsEmptyStack(Stack *pStack): 스택이 비어있는지를 검사합니다.

CountStackItem(Stack *pStack): 스택에 얼마만큼의 항목이 있는지 알아봅니다.


## 2. Queue
컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어 넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조로 저장하는 형식입니다. 큐(Queue)는 FIFO(First-In-First-Out) 를 따릅니다.

### ▸ Array를 이용한 기본 structure는 다음과 같습니다.

typedef struct {

	element *queue;
	
	int front, rear;
	
	int size;

}Queue;

### ▸ Linked List를 이용한 기본 structure는 다음과 같습니다.

typedef struct QNode {

	char data;
	
	struct QNode *link;

}QNode;


typedef struct {

	QNode *front, *rear;

}Queue;

### ▸다음과 같은 연산을 포함합니다.
Queue *createQueue(): 큐를 생성합니다.

isEmptyQueue(Queue *Q): 큐가 비어있는지를 검사합니다.

int isFullQueue(Queue *Q): 큐가 가득 차 있는지를 검사합니다.

enQueue(Queue *Q, element item): 큐에 item을 추가합니다.

deQueue(Queue *Q) : 큐에서 맨 앞의 item을 뺍니다.

peek(Queue *Q) : 큐에서 맨 앞의 item이 무엇인지 볼 수 있습니다.



## 3. List
순서가 있는 데이터의 모임입니다.

### ▸ Array를 이용한 기본 structure는 다음과 같습니다.

typedef struct List {

	element *data;
	
	int size;
	
	int count;

}List;

### ▸ Linked List를 이용한 기본 structure는 다음과 같습니다.

typedef struct ListNode {

	element data;
	
	struct ListNode * link;

}ListNode;

typedef struct HeadNode {

	int count;
	
	ListNode *head;

}List;

### ▸다음과 같은 연산을 포함합니다.
IsEmptyList(List *list) : List가 비어있는지를 검사합니다.

IsFullList(List *list) : List가 가득 차 있는지를 검사합니다.

CreateList(int size) : size만큼의 리스트를 만듭니다.

_insertList(List *list, int location, element data) : data를 List의 location에 해당하는 자리에 넣습니다.

SearchList(List *list, element key) : key를 가진 data를 List에서 찾습니다.

RemoveNode(List *list, element data) : key를 가진 data를 list에서 찾아 없앱니다.

void DestroyList(List *list) : list를 삭제합니다.



## 4. 그 외
C언어를 이용한 데크가 구현되어있습니다.



## 5. 참고 자료
https://gmlwjd9405.github.io/2018/08/03/data-structure-stack.html

https://gmlwjd9405.github.io/2018/08/02/data-structure-queue.html
