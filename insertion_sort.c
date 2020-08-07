#include <stdlib.h>

int* ins_sort(int data_ori[], int size)
{
	int* data = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		data[i] = data_ori[i];
	}

	// 0. Select number from the beginning of the array.
	for (int i = 1; i < size; i++)
	{
		int key = data[i];
		// 1. Iterate from data[1] to data[n] over the array.
		int j;
		for (j = i; j > 0; j--)
		{
			// 2. If the key element is smaller than its predecessor, compare it to the elements before.
			if (data[j - 1] > key) 
			{
				// Move the greater elements one position up to make space for the swapped element.
				data[j] = data[j - 1];
			}
			else 
			{
				// 3. If the data is smaller than the value stored in "key" then break the loop.
				break;
			}
		}
		// 4. Insert the data stored in "key" into the empty space.
		data[j] = key;
	}

	return data;
}
