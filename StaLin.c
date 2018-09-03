#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int counter = 0;
struct node
{
	int data;
	struct node *next;
}*top = NULL, *temp = NULL;
void insert (int item)
{
	struct node *p, *q;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	p->next=NULL;
	
	if(top == NULL)
	{
		top = p;
		return;
	}
	else
	{
		p->next=top;
		top=p;
	}
}
void pop ()
{
	struct node *q;
	q=top;
	if(top==NULL)
	{
		printf("Stalin is empty\n");
	}
	else
	{
		printf("Deleting value = %d\n",top->data);
		top=top->next;
		free(q);
	}
}
/*
void display ()
{
	struct *q;
	q=top;
	while(q!=NULL)
	{
		printf("%d\n",q->data);
		q=q->next;
	}
}
*/
int main ()
{
	
}