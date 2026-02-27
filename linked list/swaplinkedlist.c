// How to swap two nodes in a linked list?
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

// struct swapnodes(struct node **start, int x, int y);
void swapnodes(struct node **start, int x, int y)
{
    struct node *preptrX= NULL;
    struct  node *ptrX= *start;
    struct node *preptrY= NULL;
    struct node *ptrY= *start;

    // direct return if x=y
    if(x==y)
    return;

    //search 'x'
    while((ptrX && ptrX-> data) !=x){
        preptrX= ptrX;
        ptrX = ptrX->next;
    }

    //search 'y'
    while((ptrY && ptrY -> data) !=y){
        preptrY= ptrY;
        ptrY = ptrY->next;
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

int main(){
    struct node *start= NULL;
    push (&start, 20);
    push (&start, 13);
    push (&start, 17);
    push (&start, 2);
    push (&start, 22);

    printf("before swap:\n");
    printlist(start);

    swapnodes(&start, 17,20);
    printf("after swap:\n");
    printlist(start);
}
