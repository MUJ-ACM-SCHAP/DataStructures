//A program to convert a decimal number to binary 
#include<stdio.h>
int a[10];
int top=-1;
void push (int rem)
{
	if(top==9){printf("Too many elements\n");}
	else a[++top]=rem;
}
void display ()
{
	for(int i = top;i>=0;i--){printf("%d\n",a[i]);}
}
int main ()
{
	printf("Enter the number you want to convert : ");
	int ab;
	scanf("%d",&ab);
	do
	{
		push(ab%2);
		ab=ab/2;
	}while(ab>0);
	printf("The conversion of the number is : \n");
	display();
	return 0;
}