//reverse circular list
#include<stdio.h>
#include<stdlib.h>
struct Node{int data; struct Node *next ;};

struct Node *reverse(struct Node *start){
    struct Node * prev = NULL;
    struct Node * current = start;
    struct Node * nextNode = start;
    struct Node * last= start;

    //find last node
    while(last -> next != start)
    last = last->next;

    do
    { //reverse process
        nextNode= current->next;
        current-> next = prev;
        prev =current;
        current= nextNode;
    }
    while(current!=start);

    //fix circular links
    start-> next= prev;
    last-> next = prev;
    return prev;
}

void display (struct Node *start){
    struct Node *temp = start;
    if(start == NULL)
    return;

    do{
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    while(temp!= start);
    printf("\n");
}

// int main(){
//     struct Node *start = NULL, *second, *third;
//     start = (struct Node*)malloc(sizeof(struct Node));
//     second = (struct Node*)malloc(sizeof(struct Node));
//     third = (struct Node*)malloc(sizeof(struct Node));

//     start->data= 10;
//     second->data= 20;
//     third->data= 30;


//     //circular link
//     start-> next= second;
//     second-> next = third;
//     third-> next= start;

//     printf("original list:");
//     display(start);

//     start=reverse(start);

//     printf("reversd list:");
//     display(start);

// }

int main(){
    struct Node * start = NULL, * temp = NULL, *newNode;
    int n,i,value;
    printf("Enter number of nodes:");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        newNode = (struct Node *)malloc(sizeof (struct Node));
        printf("Enter data for node %d:", i+1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        if(start == NULL){
            start = temp = newNode;
            newNode-> next =start;
        }
        else
        {
            temp-> next = newNode;
            newNode-> next =start;
            temp = newNode;

        }
    }
    printf("\noriginal list:\n");
    display(start);

    start=reverse(start);

    printf("\nreversd list:\n");
    display(start);
}