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
	// Prints A:B:C:D:

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
	// Prints A:B:C:D:


	return 0;
}

pNODE append2(pNODE curr, char data) {
	// 1. Check if the current node is empty.
	// If it's empty then the node before this is the last node.
	if (curr == NULL) {
		// 
		return get_node(data);
	}

	// Checking for the next node.
	curr->next = append2(curr->next, data);

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
	// 0. If the list is empty.
	if (*phead == NULL)
	{
		*phead = get_node(data);
		return;
	}

	// 1. Check the current last node.
	pNODE tail = *phead;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	// tail points towards the last node.

	// 2. Assign the very next node of the last node as a new node.
	tail->next = get_node(data);
}
