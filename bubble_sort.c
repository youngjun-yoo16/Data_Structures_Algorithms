#include <stdio.h>

int main()
{
	int data[] = { 1, 5, 4, 9, 0, 7 };
	int size = sizeof(data) / sizeof(int);
	int tmp = 0;

	// 1. Select number from the beginning of the array.
	for (int i = 0; i < size; i++)
	{
		// 2. Search the smallest number from selected number to the number at the end of the array.
		int min = i;
		// For storing the index of the selected number.

		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}

		// 3. Exchange the selected number and the smallest number which we just found.
		int tmp = data[min];
		data[min] = data[i];
		data[i] = tmp;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d", data[i]);
	}

	printf("\n");

	return 0;
}
