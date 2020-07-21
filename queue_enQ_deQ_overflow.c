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
	add(i);				// This line
	((i + 1) % MAX);		// gets converted to this line and then compiled.

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
	// Prints A:B:C:D:

	for (int i = 0; i < 4; i++)
	{
		printf("%c: ", deQ());
	}
	printf("\n");
	// Prints A:B:C:D:

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
		char tmp = deQ();     // if deQ succeeds, then returns ASCII code instead of character (ASCII code is always greater than 0). 
				      // if deQ fails it returns "-1" and hence the loop breaks.
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

	// Changes the position which "front" is pointing towards.
	// front += 1;
	front = add(front);

	// If succeeds, return dequeued data.
	return temp;
}

int enQ(char data)
{
	if (is_full())
	{
		return -1;
	}
	// Inserting data into the position which "rear" is pointing towards.
	queue[rear] = data;

	// Changes the position which "rear" is pointing towards.
	// rear += 1;
	rear = add(rear);

	// If succeeds, return 0.
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
