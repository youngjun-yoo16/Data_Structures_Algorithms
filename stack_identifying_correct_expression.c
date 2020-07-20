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
inline is_empty(pNODE* ptop);

void test(int x)
{
	if (x == 1) return;
	printf("%d:", x);

	if (x % 2 == 0)
		test(x - 1);
	else
		test(x - 3);
	printf("%d:", x);
}

int main()
{
	pNODE top;
	top = NULL;
	char* q[] = {
		"{{1 + 3} * (4 + 5)}",		   // Correct Expression
		"({1 + 3} * (4 + 5))",		   // Correct Expression
		"1 + (3 * {4 + 5)}",		   // Wrong Expression
		"1 + 3 * (4 + 5) )",		   // Wrong Expression
		"1 + 2 * {4 + 5)",	           // Wrong Expression
		"( () () () ( (() ()) ) () )",     // Correct Expression
		NULL
	};

	for (int j = 0; q[j] != NULL; j++)
	{
		printf("%d번째 %s\n", j + 1, q[j]);
		pNODE stack = NULL;
		int flag = 0;

		for (char i = 0; q[j][i] != 0; i++) // 문자열은 마지막이 무조건 0이다.
		{
			if (q[j][i] == '(')
			{
				push(&stack, '(');
			}

			if (q[j][i] == '{')
			{
				push(&stack, '{');
			}

			if (q[j][i] == ')')
			{
				char tmp = pop(&stack);
				if (tmp != '(')
				{
					flag = 1;
					break;
				}
			}

			if (q[j][i] == '}')
			{
				char tmp = pop(&stack);
				if (tmp != '{')
				{
					flag = 1;
					break;
				}
			}
		}

		if (!is_empty(&stack))
		{
			flag = 1;
		}
		if (flag)
		{
			printf("Wrong Expression\n");
		}
		else
		{
			printf("Correct Expression\n");
		}
	}

	test(10);
	printf("\n");
	pNODE st = NULL;
	pNODE st2 = NULL;
	int x = 10;
	push(&st, x);

	while (!is_empty(&st))
	{
		x = pop(&st);

		if (x == 1) continue;
		printf("%d:", x);

		if (x % 2 == 0)
		{
			push(&st, x - 1);
		}
		else
		{
			push(&st, x - 3);
		}
		push(&st2, x);
	}

	while (!is_empty(&st))
	{
		printf("%d:", pop(&st2));
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
	if (is_empty(ptop))
	{
		return -1;
	}
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
