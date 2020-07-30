#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
} NODE, * pNODE;

pNODE get_node(char data);
void append(pNODE* phead, char data);
pNODE append2(pNODE phead, char data);

void insert(pNODE head, char srh, char data);
pNODE insert2(pNODE head, char srh, char data);

pNODE search(pNODE head, char data);
pNODE search2(pNODE curr, char data);

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

	insert(head, 'B', 'b');
	for (pNODE i = head; i != NULL; i = i->next)
	{
		printf("%c:", i->data);
	}
	printf("\n");
	// A:B:b:C:D:

	return 0;
}

pNODE insert2(pNODE curr, char srh, char data)
{
	if (curr == NULL)
	{
		return NULL;
	}
	else if (curr->data == srh)
	{
		// 삽입
		pNODE new = get_node(data);
		new->next = curr;
		return new;
	}
	else
	{
		// 재귀
		curr->next = insert2(curr->next, srh, data);
		return curr;
	}
}

void insert(pNODE head, char srh, char data)
{
	// 1. 데이터가 srh 와 같은 노드 탐색
	// search 함수를 사용하지 않고 작성해봅시다
	pNODE curr = head;
	// curr = search(head, srh)
	for (curr = head; curr != NULL; curr = curr->next)
	{
		if (curr->data == srh)
		{
			break;
		}
	}

	// 만약 노드를 찾지 못했으면(찾는 노드가 없으면)
	if (curr == NULL)
	{
		// 함수 종료
		return;
	}

	// curr 은 찾으려는 노드
	// 2. 찾아낸 노드의 뒤에 새로운 노드를 삽입
	pNODE new = get_node(data);
	new->next = curr->next;
	curr->next = new;

}

pNODE search2(pNODE curr, char data)
{
	// 노드를 찾았거나, 끝까지 가도 못찾았을때
	if (curr == NULL || curr->data == data)
	{
		// 탈출
		return data;
	}
	// curr 가 curr->next 로 변했으면...
	return search2(curr->next, data);
}

pNODE search(pNODE head, char data)
{
	pNODE curr;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		if (curr->data == data)
		{
			break;
		}
	}
	// curr 은 찾고자 하는 데이터를 가진 노드 아니면 NULL

	return curr;
}

pNODE append2(pNODE curr, char data)
{
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
