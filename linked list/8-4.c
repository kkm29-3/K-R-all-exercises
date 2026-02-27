#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

//linked list
struct node
{
  int data;
  struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
// void swapnodes(struct node **start, int x, int y);

int main(int argc, char *argv[])
 {
  int option;
  do
  {
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1:  Create a list");
    printf("\n 2:  Display the list");
    printf("\n 3. Swap two nodes");
    printf("\n 4: EXIT");

    printf("\n\n Enter your option : ");
    scanf("%d", &option);

    switch(option)
    {
        case 1: start = create_ll(start);
        printf("\n LINKED LIST CREATED");
        break;
        case 2: start = display(start);
        break;
        case 3: 
        int x;
        printf("swap of node1:");
        scanf("%d", &x);

        int y;
        printf("swap of node2: ");
        scanf("%d", &y);

        start= swapnodes(struct node **, int,  int)
        break;
    
    }
    }
    while(option !=4);
    getch();
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num!= -1)
 {
    new_node = (struct node*)malloc(sizeof(struct node)); //memory allocation
    new_node -> data=num;
    if(start==NULL)
  {
    new_node -> next = NULL;
    start = new_node;
  }
  else
    {
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next = new_node;
    new_node->next=NULL;
  }
    printf("\n Enter the data : ");
    scanf("%d", &num);
 }
    return start;
}


struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
  printf("\t %d", ptr -> data);
  ptr = ptr -> next;
 }
    return start;
}

void swapnodes(struct node **start, int x, int y)
{
    struct node *preptrX= NULL;
    struct  node *ptrX= *start;
    struct node *preptrY= NULL;
    struct node *ptrY= *start;

     // direct return if x=y
    if(x==y)
    return;

    while((ptrX && ptrX-> data) !=x){
        preptrX = ptrX;
        ptrX = ptrX -> next;

    }

    while((ptrY && ptrY -> data)!=y){
        preptrY= ptrY;
        ptrY = ptrY-> next;
    }
    //either x or y is not present
    if(!ptrX || !ptrY)
    return;

    //x is not start
    if(preptrX)
        preptrX-> next = ptrY;
    else
        *start= ptrY;

    //y is not start
    if(preptrY)
        preptrY-> next = ptrX;
    else
        *start= ptrX;

    //swap next ptrs
    struct node *temp = ptrY-> next;
    ptrY-> next= ptrX->next;
    ptrX -> next= temp;
}

void push(struct node **start, int data)
{
    struct node *newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode-> next= *start;
    *start = newNode;
}

void printlist(struct node *node)
{
    while(node)
    {
        printf("%d ", node->data);
        node = node-> next;
    }
    printf("NULL\n");
}


// int main(){
//     struct Node *start= NULL;
//     push (&start, 20);
//     push (&start, 13);
//     push (&start, 17);
//     push (&start, 2);
//     push (&start, 22);

//     printf("before swap:\n");
//     printlist(start);
//     swapnodes(&start, 17,20);
//     printf("after swap:\n");
//     printlist(start);
// }