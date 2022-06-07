## [문제] 리스트 구현

이중연결리스트를 이용하여 영문자 리스트 ADT를 구현하시오.

다음 네가지 연산을 지원해야 함
- add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
- delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다.
- get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
- print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.

순위 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position:을 출력하고, 해당 연산을 무시한다.

## 입력

- 각 연산의 내용이 한 줄에 한 개씩 입력되고, 한 개의 줄에는 연산의 종류, 순위, 원소 순서로 입력된다.
- 연산의 종류 : 연산 이름의 맨 앞 영문자가 대문자 A, D, G, P로 주어진다.
- 순위 : 양의 정수
- 원소 : 영문자(대문자, 소문자 모두 가능)


## 출력

P가 입력되었을 때 list의 모든 원소를 출력한다.

-----

## 풀이

이중연결리스트를 이용하여 리스트 ADT를 처음 구현하였는데 P를 입력하였을 때 출력이 되지 않음.

```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	struct node* prev;
	char elem;
}Node;

Node* add(Node* head, int r, char e) {
	int i, n=0;
	Node *p, *q;
	p = head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
    		printf("invalid position");
		return 0;
  	}
  else {
	p = head;
	for (i = 1; i <= r - 1; i++)  // 순위가 r인 노드까지 이동
		p = p->next;
	q->elem = e;  // q의 원소에 e 대입
	q->prev = p->prev;  // 연결
	q->next = p;
	(p->prev)->next = q;
	p->prev = q;
	n += 1;
	return head;
  }
}
char delete(Node* head, int r) {
	int n = 0, i;
	char e;
	Node* p = head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
    		printf("invalid position");
		return 0;
  	}
  else {
	p = head;
	for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
		p = p->next;
	e = p->elem;  
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	n -= 1;
	return e;
    }
}

char get(Node* head, int r) {
	int n = 0, i;
	Node* p = head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
    		printf("invalid position");
		return 0;
  	}
  else {
	p = head;
	for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
		p = p->next;
	return p->elem;
   	}
}

void print(Node* head) {
	int n = 0, i;
	Node* p = head;
	for (i = 1; i <= n; i++) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}
int main(void) {
	int n, r, i;
	char k, elem;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* trail = (Node*)malloc(sizeof(Node));
	head->next = trail;
	head->prev = NULL;
	trail->prev = head;
	trail->next = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
    	while(getchar() != '\n');
		if (k == 'A') {
			scanf("%c %d %c", &k, &r, &elem);
			add(head, r, elem);
		}
		else if (k == 'D') {
			scanf("%c %d", &k, &r);
			delete(head, r);
		}
		else if (k == 'G') {
			scanf("%c %d", &k, &r);
			get(head, r);
		}
		else if (k == 'P') {
			print(head);
		}
	}
	return 0;
}
```

LIST 라는 구조체를 만든 후, 구조체 포인터를 매개변수로 사용하여 함수를 호출하였는데 똑같이 P에서 출력을 하지 않았다. 이유는?

```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	struct node* prev;
	char elem;
}Node;

typedef struct LIST {
	Node* head;
	Node* trail;
}LIST;

void init(LIST* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->trail = (Node*)malloc(sizeof(Node));
	list->head->next = list->trail;
	list->head->prev = NULL;
	list->trail->prev = list->head;
	list->trail->next = NULL;
}

void add(LIST* list, int r, char e) {
	int i, n = 0;
	Node* p, * q;
	p = list->head->next;
	q = (Node*)malloc(sizeof(Node));
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
		printf("invalid position");
	}
	else {
		p = list->head;
		for (i = 1; i <= r - 1; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		q->elem = e;  // q의 원소에 e 대입
		q->prev = p->prev;  // 연결
		q->next = p;
		(p->prev)->next = q;
		p->prev = q;
		n += 1;
	}
}
void delete(LIST* list, int r) {
	int n = 0, i;
	char e;
	Node* p = list->head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
		printf("invalid position");
	}
	else {
		p = list->head;
		for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		e = p->elem;
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		free(p);
		n -= 1;
	}
}

char get(LIST* list, int r) {
	int n = 0, i;
	Node* p = list->head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
		printf("invalid position");
		return 0;
	}
	else {
		p = list->head;
		for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		return p->elem;
	}
}

void print(LIST* list) {
	int n = 0, i;
	Node* p = list->head;
	for (i = 1; i <= n; i++) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}

int main(void) {
	int n, r, i;
	char k=0, elem;
	LIST list;
	init(&list);
	scanf("%d", &n);
	while (getchar() != '\n');
	for (i = 0; i < n; i++) {
		while (getchar() != '\n');
		if (k == 'A') {
			scanf("%c %d %c", &k, &r, &elem);
			add(&list, r, elem);
		}
		else if (k == 'D') {
			scanf("%c %d", &k, &r);
			delete(&list, r);
		}
		else if (k == 'G') {
			scanf("%c %d", &k, &r);
			get(&list, r);
		}
		else if (k == 'P') {
			print(&list);
		}
	}
	return 0;
}
```
scanf를 사용할 때 공백을 getchar()으로 잡아줌.
n의 값에 따른 함수의 실행 여부 확인

```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	struct node* prev;
	char elem;
}Node;

typedef struct LIST {
	Node* head;
	Node* trail;
}LIST;

void init(LIST* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->trail = (Node*)malloc(sizeof(Node));
	list->head->next = list->trail;
	list->head->prev = NULL;
	list->trail->prev = list->head;
	list->trail->next = NULL;
}

void add(LIST* list) {
	int i, n = 0, r;
	char e;
	Node* p, * q;
	scanf("%d %c", &r, &e);
	getchar();
	p = list->head->next;
	q = (Node*)malloc(sizeof(Node));
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
		printf("invalid position\n");
		return;
	}
	else {
		p = list->head;
		for (i = 1; i <= r ; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		q->elem = e;  // q의 원소에 e 대입
		q->prev = p->prev;  // 연결
		q->next = p;
		(p->prev)->next = q;
		p->prev = q;
		n += 1;
	}
}
void delete(LIST* list) {
	int n = 0, i, r;
	char e;
	scanf("%d", &r);
	getchar();
	Node* p = list->head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r > n)) {
		printf("invalid position\n");
		return;
	}
	else {
		p = list->head;
		for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		e = p->elem;
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		free(p);
		n -= 1;
	}
}

void get(LIST* list) {
	int n = 0, i, r;
	Node* p = list->head->next;
	scanf("%d", &r);
	getchar();
	while (p != NULL) {
		n++;
		p = p->next;
	}
	if ((r < 1) || (r >= n)) {
		printf("invalid position\n");
		return;
	}
	else {
		p = list->head;
		for (i = 1; i <= r; i++)  // 순위가 r인 노드까지 이동
			p = p->next;
		printf("%c\n", p->elem);
	}
}

void print(LIST* list) {
	int n = 0, i;
	Node* p = list->head->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	p = list->head;
	for (i = 1; i <= n; i++) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}

int main(void) {
	int n, i;
	char k=0;
	LIST* list=(LIST*)malloc(sizeof(LIST));
	init(list);
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &k);
		getchar();
		if (k == 'A') {
			add(list);
		}
		else if (k == 'D') {
			delete(list);
		}
		else if (k == 'G') {
			get(list);
		}
		else if (k == 'P') {
			print(list);
		}
	}
	return 0;
}
```
<br>
