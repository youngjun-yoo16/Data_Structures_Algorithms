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
	// A: B: C: D:

	int size = top;
	for (int i = 0; i < size; i++)
	{
		printf("%c: ", pop());
	}
	printf("\n");
	// D: C: B: A:

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
	// 이미 꽉차있다면 push 실패
	if (is_full())
		return -1;

	// 스택의 가장 위에 데이터 삽입
	stack[top] = data;

	// top의 위치를 변경
	top += 1;

	// 성공시 0 반환
	return 0;
}

char pop()
{
	// 이미 비어있다면 실패
	if (is_empty())
		return -1;

	// top의 위치를 변경
	top -= 1;

	// 스택에 가장 위에 있는 데이터 반환
	return stack[top];
}

int is_full()
{
	// 스택이 가득 차있는 경우 1
	// 아닌 경우 0 반환
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
	// 스택이 텅 비어있는 경우 1
	// 아닌 경우 0 반환
	return (top == 0);
}
