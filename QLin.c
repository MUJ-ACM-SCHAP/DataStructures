#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *next;
}*front = NULL, *rear = NULL;

void push (int item)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->next=NULL;
	p->data=item;
	if(rear == NULL)
	{
		rear = p;
		front = p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
}
void display ()
{
	struct node *p;
	//p=(struct node *)malloc(sizeof(struct node));
	p=front;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
		//counter++;
	}
}
void pop ()
{
	if(rear==front)
	{
		printf("Cannot Delete\n");
	}
	else
	{
		struct node *p;
		p=front;
		printf("The element which is being deleted is  as follows : %d\n",front->data);
		front=front->next;
		free(p);
	}
}
int main ()
{
	int num = 0;
	while(num!=4)
	{
		printf("Enter your choice : ");
		scanf("%d",&num);
		if(num == 1){int item;printf("Enter the element you want to push : ");scanf("%d",&item);push(item);}
		if(num == 2){pop();}
		if(num == 3){display ();}
	}
	return 0;
}