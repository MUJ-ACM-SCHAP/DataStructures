#include<stdio.h>
float a[10];
int top = -1;
void push (float item)
{
	if(top==9)printf("Overflow, too many elements\n");
	else a[++top]=item;
}
void pop ()
{
	if(top==-1)printf("Underflow, no element present\n");
	else {printf("The element which is being deleted is %f",a[top]);top--;}
}
void display ()
{
	for(int i = top;i>=0;i--)printf("%f\n",a[i]);
}
int main ()
{
	printf("You have three choices : 1. Push () 2. Pop () 3. Dislpay () 4. Exit ()\n");
	int num;
	do
	{
		printf("Enter your choice : ");
		scanf("%d",&num);
		if(num==1){float item;printf("Enter the number you want to push in : ");scanf("%f",&item);push(item);}
		if(num==2){pop();}
		if(num==3){display();}
	}while (num!=4);
	return 0;
}