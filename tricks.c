#include <stdio.h>
#include <stdlib.h>	
#define MAX 101
#define SWAP(X, Y, T) (T=X, X=Y, Y=T)
#define COMPARE(X,Y) ((X<Y)?-1:(X==Y)?0:1)
void create_array(int a[], int n)
{
	int j;
	for (j = 0; j < n; j++)
		scanf("%d", &a[j]);	
}
void random_array(int list[], int n)
{
	int i;
	if ((n<1)||(n>MAX))
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < n; ++i)
	{
		list[i] = rand()%1000;
		printf("%d ", list[i]);
	}
	printf("\n");
}
void print_array(int a[], int n)
{
	int j;
	for (j = 0; j<n; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\n");
}
int sum_array(int a[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	return sum;
}
int isPrime(int n)
{
    if(n <= 1) 
        return 0;
    if(n <= 3) 
        return 1;
    if (n % 2 == 0 || n % 3 == 0) 
        return 0;
    int i = 5;
    while(i * i <= n)
    { 
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6
    }
    return 1;
}
void selection_sort(int a[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n-1; ++i)
	{
		min = i;
		for (j = i+1; j < n; ++j)
		{
			if (a[j]<a[min])
			{
				min = j;
			}
		}
		SWAP(a[min], a[i], temp);
	}
}
void bubble_sort(int a[], int n)
{
   int i, j, t; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (a[j] > a[j+1]) 
              SWAP(a[j], a[j+1], t); 
}
void linear_search(int a[], int size, int fai)
{
	int ele, c=0;
	printf("Enter element\n");
	scanf("%d", &ele);
	for (int i = 0; i <=fai; ++i)
	{
		if (ele == a[i])
		{
			printf("Found it's position: %d\n", (i+1));
			c++;
		}
	}
	if (c == 0)
	{
		printf("Not Found\n");		
	}
}
int dec2bin(int n)
{
	if (n < 2)
		return n;
	int x = 0, i = 0;
	while(n != 0)
	{
		x += (n%2)*pow(10, i++);
		n = n/2;
	}
	return x;
}
int binary_search(int a[], int ele, int left, int right)
{
	int middle;
	if(left<=right)
	{
		middle = (left+right)/2;
		switch(COMPARE(a[middle], ele))
		{
			case -1:return binary_search(a, ele, middle+1, right);
			case 0:return middle;
			case 1:return binary_search(a, ele, left, middle-1);
		}
		return -1;
	}
}
int main()
{
	int t;
	scanf("%d", &t); 
	while(t--)
	{
		int n;
		printf("Enter number of elements: ");
		scanf("%d", &n);
		char s[n];
		fgets(s, sizeof(s), stdin);
		int a[n];
	}
	return 0;
}
