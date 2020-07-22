#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node* next;
};
typedef struct node NODE, * pNODE;

struct queue {
	pNODE rear;
	pNODE front;
};
typedef struct queue Q;

// 새로 동적할당으로 노드를 만들고
// 노드의 값을 초기화 하는 함수
pNODE get_node(char data);
int enQ(Q* queue, char data);
char deQ(Q* queue);

int main()
{
	// pNODE front = NULL;
	// pNODE rear = NULL;
	pNODE head = get_node(0);
	Q q = { .front = head, .rear = head };
	enQ(&q, 'A');
	enQ(&q, 'B');
	enQ(&q, 'C');
	enQ(&q, 'D');

	// front는 가장 앞에 있는 A노드의 주소
	// rear은 가장 마지막 노드 D의 주소
	// D->next는 NULL
	for (pNODE i = q.front; i != NULL; i = i->next)
	{
		printf("%c:", i->data);
	}
	printf("\n");
	// A:B:C:D:

	while (q.front != q.rear)	//q.front는 항상 빈 노드를 가르키고 있다고 가정
	{
		printf("%c:", deQ(&q));
	}
	printf("\n");

	return 0;
}

char deQ(Q* queue)
{
	if (queue->front == queue->rear) return -1;

	// front의 다음 노드 임시 저장 (free 용)
	pNODE next = queue->front->next;

	// front가 가르키는 노드 free		
	free(queue->front);

	// front를 front의 다음노드로 변경
	queue->front = next;

	// 데이터 반환
	return next->data;
}

int enQ(Q* queue, char data) {
	// 새로운 노드를 만듦
	// 만들어진 노드 초기화
	pNODE new = get_node(data);

	if (new == NULL) return -1;

	// 만약 현재 노드가 비어있다면 
			// front가 새로운 노드를 가르키도록
	// 아니라면 (큐가 있다면)
			// 기존 queue와 새로 만든 노드를 연결(rear와 연결)
	/*if (queue->front == NULL)
	{
		queue->front = new;
	}
	else
	{
		queue->rear->next = new;
	}*/

	queue->rear->next = new;
	// rear가 새로운 노드를 가르키도록 변경
	queue->rear = new;

	// 성공시 0 반환
	return 0;
}

// 새로 동적할당으로 노드를 만들고 노드의 값을 초기화하는 함수
pNODE get_node(char data)
{
	pNODE new = malloc(sizeof(NODE));
	if (new == NULL) return NULL;
	new->data = data;
	new->next = NULL;
	return new;
}
