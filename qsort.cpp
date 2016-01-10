#include <stdio.h>


int data[15] = {0, 100, 23, 34, 77, 10, 8, 1, 5, 9, 4, 7, 3, 2, 6};

void swap(int *arr, int left, int right) {
	int temp;
	temp=arr[left];
	arr[left]=arr[right];
	arr[right]=temp;
}

void qsort(int *arr, int left, int right) {
	int start, end;
	int pivot;

	if (right-left <=0) return;

	start=left;
	end=right;
	pivot=arr[left++];

	while(1) {
		while((arr[left] < pivot) && (left <= end)) left++;
		while((pivot < arr[right]) && (right > start)) right--;
		if(right > left) swap(arr, left, right);
		else {
			swap(arr, start, right);
			break;
		}
	}
	qsort(arr,start,right-1);
	qsort(arr,right+1,end);
}


void isort(int *arr, int left, int right) {
	int i, j;

	for (i=left+1; i<=right; i++) {
		for (j=i; j>left; j--) {
			if (arr[j-1] > arr[j]) swap(arr,j-1,j);
			else break;
		}
	}
}

int main(void) {
	int i;

	qsort(data, 0, 14);
//	isort(data, 0, 14);
	for (i=0; i<15; i++) printf("%d ", data[i]);
	printf("\n");
        return 0;
}
