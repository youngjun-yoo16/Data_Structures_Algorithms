#include <stdlib.h>

int* sel_sort(int data_ori[], int size) 
{
	int* data = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		data[i] = data_ori[i];
	}

	// 1. 가장 앞부터 순서대로 하나씩 선택
	for (int i = 0; i < size; i++)
	{
		// 2. 선택된 값부터 가장 마지막 까지 중
		//가장 작은 값을 찾음
		int min = i;
		// 가장 작은 값이 몇번째 값 인지
		for (int j = i; j < size; j++)
		{
			if (data[min] > data[j]) {
				min = j;
			}
		}
		// 3. 찾은 값과 선택된 값을 서로 교환
		int tmp = data[min];
		data[min] = data[i];
		data[i] = tmp;
	}

	return data;
}
