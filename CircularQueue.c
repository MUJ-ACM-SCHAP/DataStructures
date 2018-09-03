#include<stdio.h>
int rear = -1;
int front = -1;
int a[10];
void push (int item)
{
	if(rear == -1)
	{
		front = 0;
		rear = 0;
		a[rear++]=item;
	}
	else if( rear == 9 && front == 0)
	{
		printf("Cannot Insert\n");
	}
	else if (rear == 9 && front != 0)
	{
		rear = 0;
		a[rear]=item;
	}
	else if (rear != front)
		a[rear++]=item;
}
void pop ()
{
	if(front == -1)
	{
		printf("Cannot Delete\n");
	}
	else if (front<9)
	{
		front++;
	}
	else if (front == 9 && rear >0)
	{
		front == 0;
	}
	else 
		front++;
}
int main ()
{
	int a;
	do
	{
		printf("Enter your choice : ");
		scanf("%d",&a);
		if(a==1){int item; printf("Enter the value : "); scanf("%d",&item); push(item);}
		if(a==2){pop();}
	}while(a!=3);
	return 0;
}