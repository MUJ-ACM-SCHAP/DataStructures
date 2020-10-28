#include <stdio.h>
 #include <stdlib.h> 
struct Node { 
int data; 
struct Node *next; 
}; 
typedef struct Node Node; 
Node *start; void display(); void search(); 
void Insert_Beginning();
 void Insert_Last(); void Del_FirstNode(); 
void Del_LastNode(); 
void main() 
{ printf("\nDisplay"); 
printf("\nSearch for an element"); 
printf("\nInsert in beginning"); 
printf("\nInsert at last”);
 printf("\nDelete from Beginning"); 
printf("\nDelete from last"); 
printf("\nExit"); int choice = 0; while (choice != 6) { printf("\nEnter your choice: "); 
scanf("\n%d", &choice); switch (choice) { case 0: display(); break; case 1: search(); break; case 2: Insert_Beginning(); break; case 3: Insert_Last(); break; case 4: Del_FirstNode(); break; case 5: Del_LastNode(); break; case 6: exit(0); break; default: 
printf("wrong choice"); 
} } 
} void Insert_Beginning() 
{ 
Node *new_node, *ptr; int val; new_node = (Node *)malloc(sizeof(Node)); 
if (new_node == NULL) { printf("\nOVERFLOW"); } else { printf("Enter the data: "); 
scanf("%d", &val); new_node->data = val; if (start == NULL) { 
start = new_node; 
new_node->next = start; } else { ptr = start; while (ptr->next != start) ptr = ptr->next; 
new_node->next = start;
 ptr->next = new_node; 
start = new_node; } printf("Node is inserted\n"); 
} 
} void Insert_Last()
 { 
Node *new_node, *temp; int val; new_node = (Node *)malloc(sizeof(Node)); 
if (new_node == NULL) { printf("\nOVERFLOW"); } else { printf("Enter Data: "); scanf("%d", &val); new_node->data = val; if (start == NULL) { start = new_node; new_node->next = start; } else { 
temp = start; while (temp->next != start) 
{ temp = temp->next; } temp->next = new_node; 
new_node->next = start; } printf("Node is inserted\n"); 
} 
} void Del_FirstNode()
 { 
Node *ptr; if (start == NULL) { printf("\nUNDERFLOW"); } else if (start->next == start) 
{ start = NULL; free(start); printf("Node is deleted\n"); } else { ptr = start; while (ptr->next != start) ptr = ptr->next; ptr->next = start->next; 
free(start); start = ptr->next; 
printf("Node is deleted\n"); } 
} void Del_LastNode() 
{ 
Node *ptr, *preptr; if (start == NULL) { 
printf("UNDERFLOW"); 
} 
else if (start->next == start) 
{ start = NULL; free(start); 
printf("Node is deleted\n"); 
} else { 
ptr = start; while (ptr->next != start)
 { preptr = ptr; ptr = ptr->next; } preptr->next = ptr->next; 
free(ptr); printf("Node is deleted\n”);
 } 
} void search() 
{ 
Node *ptr; int val, i = 0, flag = 0; ptr = start; if (ptr == NULL) { printf("Empty List\n"); } else { printf("Enter value to be searched"); 
scanf("%d", &val); if (start->data == val) { printf("Value found at %d", i + 1); flag = 1; } else { while (ptr->next != start) { if (ptr->data == val) { printf("Value found at%d\n", i + 1); 
flag = 1; 
break; 
} 
i++; ptr = ptr->next; } } if (flag == 0) { printf("Value not found\n"); 
} } 
} void display() 
{ 
Node *ptr; ptr = start; if (start == NULL) { printf("Nothing"); 
} else { while (ptr->next != start)
 { printf("%d ", ptr->data);
 ptr = ptr->next; } 
printf("%d ", ptr->data); 
}
} 
