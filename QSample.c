//A sample implementation of Queue FIFO
#include<stdio.h>
int a[10];
int front = -1;
int rear = -1;
void push (int item)
{
	if(rear == -1)
	{
		rear = 0;
		front = 0;
		a[rear++] = item ;
	}
	else if (rear == 9)
	{
		printf("Cannot insert\n");
	}
	else 
	{	
		int j=1;
		for(int i = 1;i<=item;i++)
		{	
			j=j*i;
		}
		//printf("%d",j);
		a[rear++] = j;
	}
}
void pop ()
{
	if(rear==front)
		printf("Cannot Delete\n");
	else
		front++;
}
void display ()
{
	for(int i = front;i<rear;i++)
		printf("%d\n",a[i]);
}
int main ()
{
	printf("You have three choices : 1. Push () 2. Pop () 3. Dislpay () 4. Exit ()\n");
	int num;
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&num);
		if(num==1){int item;printf("Enter the number you want to push in : ");scanf("%d",&item);push(item);}
		if(num==2){pop();}
		if(num==3){display();}
	}while (num!=4);
	return 0;
}