#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *lchild;
	int info;
	struct node *rchild;
}*root = NULL,*root1=NULL;

void insert_nrec(int ikey)
{
	struct node *tmp,*par,*ptr;
	
	ptr=root;
	par=NULL;
	
	while(ptr!=NULL)
	{
		par = ptr;
		if(ikey<ptr->info)
			ptr=ptr->lchild;
		else if (ikey>ptr->info)
			ptr=ptr->rchild;//ptr controls the loop;
		else
		{
			printf("The key aleady exists\n");
		}
	}
	
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=ikey;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	
	if(par==NULL)
		root = tmp;
	else if (ikey<par->info)
		par->lchild=tmp;
	else
		par->rchild=tmp;//tmp is the new node. this points to it;
}
void postorder (struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ",root->info);
	}
}
void max ()
{
	struct node *par, *ptr;
	ptr = root;
	par = NULL;
	while(ptr!=NULL)
	{
		par = ptr ;
		ptr=ptr->rchild;
	}
	printf("The maximum value is : %d\n",par->info);
}
void search ()
{
	printf("Enter the element you want to search for : ");
	int item;
	scanf("%d",&item);
	struct node *ptr;
	ptr = root;
	//example of traversal
	while(ptr!=NULL)
	{
		if(ptr->info>item)
			ptr=ptr->lchild;
		else if (ptr->info<item)
			ptr=ptr->rchild;
		else if (ptr->info=item)
		{
			printf("Teh element, has been found!\n");break;
		}
	}
}
void random ()
{
	struct node *ptr;
	ptr=root;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->rchild;
	}
}
int main ()
{
	//when you think there is gonna be a switch case here ..
	//im sorry we dont do that here XD
	int num = 0;
	while (num!=6)
	{
		printf("Enter your choice : ");
		scanf("%d",&num);
		if(num== 1)
		{
			printf("Enter the ikey : ");
			int item;
			scanf("%d",&item);
			insert_nrec(item);
		}
		else if (num==2)
		{
			postorder(root);
		}
		else if (num==3)
		{
			max();
		}
		else if (num==4)
		{
			search ();
		}
		else if (num==5)
			random();
	}
	/*
	int num1,num2,num3;
	printf("Enter three values : ");
	scanf("%d",&num1);
	scanf("%d",&num2);
	scanf("%d",&num3);
	insert_nrec(num1);
	insert_nrec(num2);
	insert_nrec(num3);
	postorder(root);*/
}