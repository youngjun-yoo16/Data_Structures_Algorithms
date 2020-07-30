#include <stdio.h>

int main()
{
	int data[] = { 1, 5, 4, 9, 0, 7 };
	int size = sizeof(data) / sizeof(int);
	int tmp = 0;

	// 1. 가장 앞부터 순서대로 하나씩 선택
	for (int i = 0; i < size; i++)
	{
		// 2. 선택된 값부터 가장 마지막까지 중 가장 작은 값을 찾음
		int min = i;
		// 가장 작은 값이 몇번째 값 인지

		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}

		// 3. 찾은 값과 선택된 값을 서로 교환
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
