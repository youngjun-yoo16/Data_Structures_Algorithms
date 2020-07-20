#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
} NODE, * pNODE;
//pNODE stores the address of the struct node. 

pNODE get_node(char data);
int push(pNODE* ptop, char data);
char pop(pNODE* ptop);

int main()
{
	pNODE top;
	top = NULL;
	push(&top, 'A');
	push(&top, 'B');
	push(&top, 'C');
	push(&top, 'D');

	for (pNODE i = top; i != NULL; i = i->next)
	{
		printf("%c:", i->data);
	}
	printf("\n");
	// D:C:B:A

	while (top != NULL)
	{
		printf("%c:", pop(&top));
	}

	return 0;
}

// 노드를 만드는 함수
// data: 노드에 저장할 데이터
pNODE get_node(char data) {

	// 새로 노드를 만듬
	pNODE new = malloc(sizeof(NODE));

	// 새로 만든 노드에 데이터 초기화
	if (!new) return NULL;
	new->data = data;

	// 새로 만든 노드에 next 초기화
	new->next = NULL;

	// 새로 만든 노드 반환
	return new;
}

inline is_empty(pNODE* ptop)
{
	return *ptop == NULL;
}

char pop(pNODE* ptop)
{
	// top이 가르키는 노드의 데이터
	// 임시 저장(반환용)
	char res = (*ptop)->data;

	// top의 하나 이전 노드
	// 임시 저장(free용)
	pNODE next = (*ptop)->next;

	// top이 가르키는 노드 free
	free(*ptop);

	// top 하나 이전 노드로 변경
	*ptop = next;

	// 데이터 반환
	return res;
}

int push(pNODE* ptop, char data)
{
	// 1. 새로운 노드를 만듦.
	pNODE new = get_node(data);

	// 2. 기존 stack과 연결.
	if (!new) return -1;
	new->next = *ptop;

	// 3. top이 새로운 노드 가르킴.
	*ptop = new;

	// 성공시
	return 0;

}
