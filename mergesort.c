#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void printArray(int* arr, int len) {
	int i;
	for(i=0; i<len; i++) 
	    printf("%d ", arr[i]);
	printf("\n");
}

bool arrayEq(int* a, int* b, int len) {
	int i;
	for(i=0; i<len; i++)
	    if (a[i] != b[i])
         return false;
	return true;
}

// TDD - Test Driven Development
void merge(int* a, int low, int mid, int high) {
	int i=low;
	int j=mid+1;
	int k=low;
	int b[100];
	
	while(i<=mid && j<=high) {
		if(a[i]<a[j]) {
			b[k]=a[i];
			i++;
			k++;
         continue;
		}
      b[k]=a[j];
      j++;
      k++;
	}

	while(i<=mid) {
		b[k]=a[i];
		i++;
		k++;
	}

	while(j<=high) {
		b[k]=a[j];
		j++;
		k++;
	}
	
	for(i=low;i<=high;i++)
		a[i]=b[i];
}

void mergeSort(int* a, int low, int high) {
	if(low>=high) return;
	
   int mid=(low+high)/2;
   mergeSort(a,low,mid);
   mergeSort(a,mid+1,high);
   merge(a,low,mid,high);
}

int main() {
	int arr[] = {9, 4, 14, 4, 15, 6, 70};
	int len = sizeof(arr) / sizeof(arr[0]);
		
	mergeSort(arr,0,len-1);
	
	int result[] = {4, 4, 6, 9, 14, 15, 70};
	assert(arrayEq(arr, result, len));
	
	return 0;
}
