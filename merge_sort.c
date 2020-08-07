#include <stdlib.h>
#include "merge_sort.h"

int* merge_sort(int data_ori[], int size) {
	int* data = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		data[i] = data_ori[i];
	}

	int* buff = malloc(sizeof(int) * size);
	//buff 는 buffer 의 약자로 보통 사용
	_merge_sort(data, 0, size - 1, buff);

	return data;
}

void merge(int data[], int start, int mid, int end, int buff[]) {
	//1. 두 배열의 각각 가장 앞에 커서를 위치하고 시작
	int l = start;
	int l_end = mid;
	int r = mid + 1;
	int r_end = end;
	int i = start;
	//4. 2 - 3번을 한쪽 커서가 범위를 벗어나기 전 까지 반복
	while (l <= l_end && r <= r_end) {
		//2. 두 커서가 가르키는 값들 중, 더 작은 값을 임시 배열에 저장
		if (data[l] < data[r]) {
			//3. 저장된 값을 가르키던 커서는 뒤로 한칸 이동
			buff[i] = data[l];
			l++;
		}
		else {
			//3. 저장된 값을 가르키던 커서는 뒤로 한칸 이동
			buff[i] = data[r];
			r++;
		}
		i++;
	}

	//5. 범위를 벗어나지 않은 쪽 배열의 나머지 값을 임시배열에 순차적으로 저장
	if (l > l_end) {
		for (int j = r; j <= r_end; j++)
		{
			buff[i++] = data[j];
		}
	}
	else {
		while (l <= l_end) {
			buff[i++] = data[l++];
		}
	}
	//6. 임시 배열에 저장된 정렬된 배열을 원본 배열에 복사
	i = start;
	while (i <= end) {
		data[i] = buff[i];
		i++;
	}
}

void _merge_sort(int data[], int start, int end, int buff[]) {
	//탈출조건(현재 나눠진 배열에 데이터가 1개 이하인 경우)
	if (end - start <= 0) return;
	int mid = (end + start) / 2;
	//왼쪽 재귀
	_merge_sort(data, start, mid, buff);
	//오른쪽 재귀
	_merge_sort(data, mid + 1, end, buff);
	//여기서 합치는 함수 수행 <-- 얘의 위치를 정해주세요
	merge(data, start, mid, end, buff);
}
