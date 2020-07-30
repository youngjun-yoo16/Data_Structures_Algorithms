#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node* next;
};
typedef struct node NODE, * pNODE;

pNODE get_node(char data);
void append(pNODE* phead, char data);
pNODE append2(pNODE phead, char data);

int main()
{
	pNODE head = NULL;
	append(&head, 'A');
	append(&head, 'B');
	append(&head, 'C');
	append(&head, 'D');

	for (pNODE i = head; i != NULL; i = i->next)
	{
		printf("%c:", i->data);
	}
	printf("\n");
	// A:B:C:D:

	head = NULL;
	head = append2(head, 'A');
	head = append2(head, 'B');
	head = append2(head, 'C');
	head = append2(head, 'D');

	for (pNODE i = head; i != NULL; i = i->next)
	{
		printf("%c:", i->data);
	}
	printf("\n");
	// A:B:C:D:


	return 0;
}

pNODE append2(pNODE curr, char data) {
	// 1. 현재 노드가 비어있는지 확인
	// (현재 노드가 비어있다면, 이전 노드가 마지막 노드)
	if (curr == NULL) {
		// 새로운 노드라고 대답
		return get_node(data);
	}

	// 내 다음노드는 뭐야?
	curr->next = append2(curr->next, data);


	// 올바른 다음 노드를 대답
	// 올바른 다음 노드: 자기 자신

	return curr;
}

pNODE get_node(char data)
{
	pNODE new = malloc(sizeof(NODE));
	if (new == NULL) return NULL;
	new->data = data;
	new->next = NULL;
	return new;
}

void append(pNODE* phead, char data) {
	// 0. 만약 리스트가 비어있다면
	if (*phead == NULL)
	{
		*phead = get_node(data);
		return;
	}

	// 1. 현재 가장 마지막 노드를 확인
	pNODE tail = *phead;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	// tail이 가장 마지막 노드를 가르키고 있음

	// 2. 현재 가장 마지막 노드의
	// 다음노드를 새로 만든 노드로 지정
	tail->next = get_node(data);
}
