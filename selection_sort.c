#include <stdlib.h>

int* sel_sort(int data_ori[], int size) 
{
	int* data = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		data[i] = data_ori[i];
	}

	// 1. Select number from the beginning of the array.
	for (int i = 0; i < size; i++)
	{
		// 2. Search the smallest number from selected number to the number at the end of the array.
		int min = i;
		// For storing the index of the selected number.
		for (int j = i; j < size; j++)
		{
			if (data[min] > data[j]) {
				min = j;
			}
		}
		// 3. Exchange the selected number and the smallest number which we just found.
		int tmp = data[min];
		data[min] = data[i];
		data[i] = tmp;
	}

	return data;
}
