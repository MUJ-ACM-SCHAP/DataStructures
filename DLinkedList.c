#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next, *prev;
}*head = NULL;
void create ()
{
	struct node *p, *q;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value you want to insert : ");
	scanf("%d",&p->data);
	p->next=NULL;
	p->prev=NULL;
	if(head==NULL)
	{
		head=p;
		return ;
	}
	q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	p->prev=q;
}
void display ()
{
	if(head==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void any (int item)
{
	
	int pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	
	struct node *p,*q;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=item;
	p->next = NULL;
	
	int counter = 0;
	q=head;
	while(q!=NULL)
	{
		++counter;
		if(counter==pos-1)
		{
			p->next=q->next;
			q->next->prev=p;
			q->next=p;
			p->prev=q;
			break;
		}
		q=q->next;
	}
	printf("The number of elements in the DLL is : %d\n",counter);
}
void search (int item)
{
	struct node *q;
	q=head;
	int counter;
	while(q!=NULL)
	{
		++counter;
		if(q->data==item)
		{
			printf("The required element was found\n");
		}
		q=q->next;
	}
}
int main ()
{
	int num = 0;
	while(num!=4)
	{
		printf("Enter the choice : ");
		scanf("%d",&num);
		if(num==1){create();}
		if(num==2){display ();}
		if(num==3)
		{
			int item;
			printf("Enter the value you want to push : \n");
			scanf("%d",&item);
			any(item);
		}
	}
}