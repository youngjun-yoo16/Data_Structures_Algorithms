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
		"{{1 + 3} * (4 + 5)}",		   // 올바른 수식
		"({1 + 3} * (4 + 5))",		   // 올바른 수식
		"1 + (3 * {4 + 5)}",		   // 잘못된 수식
		"1 + 3 * (4 + 5) )",		   // 잘못된 수식
		"1 + 2 * {4 + 5)",			   // 잘못된 수식
		"( () () () ( (() ()) ) () )", // 올바른 수식
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
			printf("잘못된 식\n");
		}
		else
		{
			printf("올바른 식\n");
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
	if (is_empty(ptop))
	{
		return -1;
	}
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
