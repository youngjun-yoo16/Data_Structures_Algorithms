#include <stdio.h>

void swap(int data[], int x, int y)
{
	int tmp = data[x];
	data[x] = data[y];
	data[y] = tmp;
}

int main()
{
	int data[] = { 1, 5, 4, 9, 0, 7 };
	int size = sizeof(data) / sizeof(int);
	int tmp = 0;

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data, j, j + 1);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d", data[i]);
	}

	printf("\n");

	return 0;
}
