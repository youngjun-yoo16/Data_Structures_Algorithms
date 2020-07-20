#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
} NODE, * pNODE;
//pNODE stores the address of the struct node. (Can be used to refer to a struct by its address)

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
	// Prints D:C:B:A.

	while (top != NULL)
	{
		printf("%c:", pop(&top));
	}

	return 0;
}

// Creating a function to make a node.
// data: The data which is to be stored in the node.
pNODE get_node(char data) {

	// Create new node by allocating the memory of an existing node (NODE).
	pNODE new = malloc(sizeof(NODE));

	// Initialize its data. 
	if (!new) return NULL;
	new->data = data;

	// Initialize the pointer variable "next" to NULL.
	new->next = NULL;

	// Return the new node.
	return new;
}

inline is_empty(pNODE* ptop)
{
	return *ptop == NULL;
}

char pop(pNODE* ptop)
{
	// Indicates the data which is stored in the "top" position.
	// For temporary storing and return purpose.
	char res = (*ptop)->data;

	// Indicates the node which is just below the "top"'s position. 
	// For temporary storing and free purpose.
	pNODE next = (*ptop)->next;

	// Free the node which the "top" is pointing towards. 
	free(*ptop);

	// Changes the position of the "top" to a node just below it.
	*ptop = next;

	// If succeeds, return data.
	return res;
}

int push(pNODE* ptop, char data)
{
	// 1. Create new node by using get_node().
	pNODE new = get_node(data);

	// 2. Connect with the original stack.
	if (!new) return -1;
	new->next = *ptop;

	// 3. "top" points towards the new node.
	*ptop = new;

	// If succeeds, return 0.
	return 0;

}
