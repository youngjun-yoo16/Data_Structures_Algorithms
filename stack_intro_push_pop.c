#include <stdio.h>
#define MAX 10

char stack[MAX];
int top;

int push(char data);
char pop();
int is_full();
int is_empty();

int main()
{
	top = 0;
	push('A');
	push('B');
	push('C');
	push('D');

	for (int i = 0; i < top; i++)
	{
		printf("%c: ", stack[i]);
	}
	printf("\n");
	// Prints A: B: C: D:

	int size = top;
	for (int i = 0; i < size; i++)
	{
		printf("%c: ", pop());
	}
	printf("\n");
	// Prints D: C: B: A:

	int d = 'A';
	while (1)
	{
		int tmp = push(d++);
		if (tmp)
			break;
	}

	size = top;
	while (1)
	{
		char tmp = pop();
		if (tmp == -1)
			break;
		else
			printf("%c:", tmp);
	}
	printf("\n");

	return 0;
}

int push(char data)
{
	// If the stack is already fully filled with data, push() fails to function.
	if (is_full())
		return -1;

	// Insert the data at the top position of the stack.
	stack[top] = data;

	// Changes the position of the top.
	top += 1;

	// If push() succeeds to function, return 0.
	return 0;
}

char pop()
{
	// If the stack is already empty, pop() fails to function.
	if (is_empty())
		return -1;

	// Changes the position of the top.
	top -= 1;

	// If pop() succeeds to function, return the data that is at the top of the stack.
	return stack[top];
}

int is_full()
{
	// If the stack is full, return 1.
	// Else return 0.
	return (top == MAX);

	/*if (top == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}*/ 
}

int is_empty()
{
	// If the stack is empty, return 1.
	// Else return 0.
	return (top == 0);
}
