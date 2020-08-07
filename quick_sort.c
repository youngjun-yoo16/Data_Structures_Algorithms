#include <stdlib.h>
#include "util.h"
#include "quick_sort.h"

int* quick_sort(int data_ori[], int size) {
	int* data = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		data[i] = data_ori[i];
	}

	_quick_sort(data, 0, size - 1);

	return data;
}

void _quick_sort(int* data, int start, int end) {
	// If data is less than 1, break.
	if (end - start <= 0) return;

	int pivot;
	pivot = partition(data, start, end);
	// Recursion by dividing into front and rear parts based on pivot.
	
	_quick_sort(data, start, pivot - 1);
	_quick_sort(data, pivot + 1, end);

}

// Returns pivot
int partition(int* data, int start, int end) {
	int sel;
	int l, r;
	// 1. Select the first element between start and end as "sel"
	// 2. Assign the index of the first element as "l" - (right after the index of "sel")
	//    Assign the index of the last element as "r" 
	sel = data[start];
	l = start + 1;
	r = end;

	while (1) {
		// 3. The left cursor proceeds until it encounters a value greater than the selected value.
		//    It must stop even when it's out of the range.
		while (l <= end && data[l] <= sel) { l = l + 1; };
		// 4. Right cursor proceeds until it meets a value lesser than the selected value
		//    It must stop even when it's out of the range.
		while (r > start && data[r] > sel) { r = r - 1; };

		//6. If two cursors cross each other (+ When ther're out of the range)

		if (l > r) {
			// Swap the selected value with the position indicated by the right cursor
			swap(data, r, start);
			break;
		}
		else {
			// 5. Swap the value of the right and left cursors
			swap(data, r, l);
		}
	}
	return r;
}
