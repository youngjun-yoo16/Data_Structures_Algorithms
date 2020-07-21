#include <stdio.h>
#define OVERFLOW

unsigned char front;
unsigned char rear;

#ifdef OVERFLOW
#define add(x) (x + 1)
#define MAX 255
#else
#define add(x)	((x+1) % MAX)
#define MAX 10
#endif

char queue[MAX];
int enQ(char data);
char deQ();

int is_empty();
int is_full();

#define add(x) ((x+1)%10)
// Macro function (Treats variable as character instead of treating as data)

int main()
{
	int i = 4;
	add(i);				// 이 내용은
	((i + 1) % MAX);		// 이 내용으로 변경 후 컴파일 수행됨

	front = rear = 0;

	enQ('A');
	enQ('B');
	enQ('C');
	enQ('D');

	for (int i = front; i < rear; i++)
	{
		printf("%c: ", queue[i]);
	}
	printf("\n");
	//A:B:C:D:

	for (int i = 0; i < 4; i++)
	{
		printf("%c: ", deQ());
	}
	printf("\n");
	//A:B:C:D:

	char dat = '1';
	while (1)
	{
		if(enQ(dat++))
		{
			break;
		}
	}

	while (1)
	{
		char tmp = deQ();     // deQ는 성공하면 ASCII Code 반환 (ASCII 코드는 0보다 큼). 즉 실패하면 -1 반환이니까 break한다.
		if (tmp < 0)
		{
			break;
		}
		printf("%c: ", tmp);
	}

	return 0;
}

char deQ()
{
	if (is_empty())
	{
		return -1;
	}

	// Temporarily store the data which is to be returned.
	char temp = queue[front];

	// front가 가르키는 위치 변경
	// front += 1;
	front = add(front);

	// 성공시 인출한 데이터 반환
	return temp;
}

int enQ(char data)
{
	if (is_full())
	{
		return -1;
	}
	// 데이터 삽입 (rear가 가르키는 위치)
	queue[rear] = data;

	// rear가 가르키는 위치 변경
	// rear += 1;
	rear = add(rear);

	// 성공시 0 반환
	return 0;
}

int is_empty()
{
	return front == rear;
}

int is_full()
{
#ifdef OVERFLOW
	unsigned char tmp = add(rear);
	return tmp == front;
#else
	return add(rear) == front;
#endif
}
