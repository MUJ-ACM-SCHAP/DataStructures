#include<stdio.h>
void swap (int* a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void print(int arr[],int size)
{
	int i;
	for(int i = 0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//this function takes last element as pivot, sorts the whole array, then places the pivot at the correct position, small elements to the left and larger elements to the right of the pivot.
int partition (int arr[],int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);//index of smaller element (defaults at -1, because low is 0, and high is 6 in the first case).
	for(int j = low;j<=high-1;j++)
	{
		//if current element is smaller than or equal to pivot.
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}
//the main function to implement quicksort
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		//pi is the partitioning index, arr[p] is now at the right place.
		int pi = partition(arr,low,high);
		print(arr,9);
		//now we will sort elements before and after pi.
		quicksort(arr,low,pi-1);
		print(arr,9);
		quicksort(arr,pi+1,high);
		print(arr,9);
	}
}
int main ()
{
	int arr [] = {4,3,1,5,9,8,2,7,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n-1);
	printf("Sorted Array :");
	print(arr,n);
	return 0;
}