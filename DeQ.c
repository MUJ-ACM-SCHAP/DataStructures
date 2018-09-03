#include<stdio.h>
int front = -1;
int rear = -1;
int a[10];
void rearpush (int item)
{
	if(rear == -1)
	{
		front = 0;
		rear = 0;
		a[rear++]=item;
	}
	else if (rear == 9)
	{
		printf("Cannot Insert\n");
	}
	else 
	{
		a[rear++]=item;
	}
}
void rearpop ()
{
	if(rear == -1)
	{
		printf("Cannot delete\n");
	}
	else if (rear>0)
	{
		printf("The element which is being deleted is, %d\n",a[--rear]);
	}
}
void frontpop ()
{
	if(front == -1)
	{
		printf("Cannot Delete\n");
	}
	else if (front == rear)
	{
		printf("Cannot Delete\n");
	}
	else
	{
		printf("The element which is being deleted is, %d\n",a[++front]);
	}
}
void frontpush(int item)
{
	if(front == -1)
	{
		printf("Cannot insert\n");
	}
	else if (front >0)
	{
		a[front--]=item;
	}
}
void display ()
{
	for(int i = front;i<rear;i++)
		printf("%d\n",a[i]);
}
int main ()
{
	printf("You have three choices : 1. FrontPush () 2. FrontPop () 3. Dislpay () 4. RearPush () 5. RearPop ()");
	int num;
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&num);
		if(num==1){int item;printf("Enter the number you want to push in : ");scanf("%d",&item);frontpush(item);}
		if(num==2){frontpop();}
		if(num==3){display();}
		if(num==4){int item;printf("Enter the number you want to push in : ");scanf("%d",&item);rearpush(item);}
		if(num==5){rearpop();}
	}while (num!=6);
	return 0;
}