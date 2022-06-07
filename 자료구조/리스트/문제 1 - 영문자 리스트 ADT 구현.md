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

<br>
