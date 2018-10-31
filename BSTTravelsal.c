#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void createtree(struct node *tree);
struct node *insert(struct node *tree, int val);
void preorder(struct node *tree);
void inorder(struct node *tree);
void postorder(struct node *tree);
int main()
{
    int option,val;

    do
    {
        printf("\n1.INSERT");
        printf("\n2.PREORDER");
        printf("\n3.INORDER");
        printf("\n4.POSTORDER");
        printf("\n5.EXIT");
        printf("\nInsert option number : ");
        scanf("%d",&option);

        createtree(tree);

        switch(option)
        {
            case 1:
                printf("Enter the value of new node:");
                scanf("%d",&val);
                tree=insert(tree,val);
                break;
            case 2:
                preorder(tree);
                break;
            case 3:
                inorder(tree);
                break;
            case 4:
                postorder(tree);

        }
    }while(option!=5);
}

void createtree(struct node *tree)
{
    tree=NULL;
}

struct node *insert(struct node *tree, int val)
{
    struct node *ptr,*nodeptr,*parentptr;

    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;

    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;

    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            nodeptr=nodeptr->right;

        }
        if(val<parentptr->data)
            parentptr->left=ptr;
        else
            parentptr->right=ptr;
    }
        return tree;
}

void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d\t",tree->data);
        inorder(tree->right);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->data);
    }
}
