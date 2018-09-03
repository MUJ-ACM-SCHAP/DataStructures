#include<stdio.h>
#include<malloc.h>
int counter = 0;
struct node 
{
	int data;
	struct node *next;
}*head = NULL, *temp = NULL;
void insert (int item)
{
	struct node *p, *q;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	p->next=NULL;
	
	if(head==NULL)
	{
		head = p;
		return;
	}
	q=head;
	while(q->next!=NULL)
		q=q->next;
	q->next =p;
}
void pre (int item)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	p->next=head;
	head=p;
}
void any (int item)
{
	struct node *p,*q;
	int count=0;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	/*
	//to find no. elements
	q=head;
	while(q->next!=NULL)
	{
		q=q->next;
		count++;
	}
	printf("The number of elements is : %d\n",count);
	*/
	printf("Enter the position you want to enter : ");
	int pos;
	scanf("%d",&pos);
	q=head;
	while(q!=NULL)
	{
		
		++count;
		if(count==pos-1)
		{
			/*
			temp=q->next;
			q->next=p;
			p->next=temp;
			*/
			p->next=q->next;
			q->next=p;
			break;
		}
		q=q->next;
	}
}
void del ()
{
	printf("Enter the position of the node you want to delete : ");
	int pos;
	scanf("%d",&pos);
	struct node *p, *q;
	int count = 0;
	q=head;
	while(q!=NULL)
	{
		++count;
		if(count==pos-1)
		{
			p=q->next;
			q->next=p->next;
			free (p);
			break;
		}
		q=q->next;
	}
}
void search ()
{
	printf("Enter the element you want to search for : ");
	int val;
	scanf ("%d",&val);
	struct node *q;
	q=head;
	while(q!=NULL)
	{
		if(q->data==val)
			printf("The value has been found !\n");
		q=q->next;
	}
}
void display ()
{
	struct node * p;
	p = head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
		counter++;
	}
}
int main ()
{
	
	int num ;
	while(num!=7)
	{
		printf("Enter the choice : ");
		scanf("%d",&num);
		if(num==1)
		{
			int item;
			printf("Enter the value you want to push : \n");
			scanf("%d",&item);
			insert(item);
		}
		if(num==2){display();}
		if(num == 3)
		{
			int item;
			printf("Enter the value you want to push : \n");
			scanf("%d",&item);
			pre(item);
		}
		if(num == 4)
		{
			int item;
			printf("Enter the value you want to push : \n");
			scanf("%d",&item);
			any(item);
		}
		if(num==5){search();}
		if(num==6){del();}
	}
	return 0;
}