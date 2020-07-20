#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE, * pNODE;
struct node {
	char data;
	pNODE next;
};

int main()
{
	NODE n = { .data = 'A' };
	printf("n: %c\n", n.data);			// Prints n: A

	NODE a = { .data = 'A' };
	NODE b = { .data = 'B' };
	NODE c = { .data = 'C' };

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	// Print the value of i.
	for (pNODE i = &a; i != NULL; i = i->next)
	{
		printf("i: %c\n", i->data);		// Prints i: A  i: B  i: C in each row.
	}

	printf("\n");

	pNODE head = malloc(sizeof(NODE));
	head->data = 'A';

	pNODE curr = head;
	for (int i = 0; i < 5; i++)
	{
		curr->next = malloc(sizeof(NODE));
		curr = curr->next;
		curr->data = 'B' + i;
		curr->next = NULL;
	}

	for (pNODE i = head; i != NULL; i = i->next)
	{
		printf("i: %c\n", i->data);		// Prints i: A  i: B  i: C  i: D  i: E  i: F in each row.
	}

	return 0;
}
