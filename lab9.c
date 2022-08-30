#include <stdio.h>
#include <stdlib.h>
#define NULL 0
typedef struct Stack{
    int data;
    struct Stack * next;
}node;
node *getNode(){
    node * new;
    new=(node*)malloc(sizeof(node));
    return (new);
}
void enqueue(node **first, node **last){
    int val;
    node *temp;
    temp=getNode();
    printf("Enter the value to enqueue??");
    scanf("%d",&val);
    temp->data=val;
    temp->next=NULL;
    if((*last)==NULL){
        (*first)=temp;
        (*last)=temp;
    }
    else{
        (*last)->next=temp;
        *last=temp;
    }
}

void dequeue(node **first, node **last){
    node * temp;
    if(*first==NULL){
        printf("Nothing in Queue!!!");
    }
    else{
        temp=(*first);
        printf("%d is deleted", temp->data);
        *first=temp->next;
        free(temp);
    }
}
void display(node **first){
    node * temp;
    temp=*first;
    printf("\n Queue items are:\t");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;

    }
    
}

int main(){
    node *first;
    node *last;
    last=NULL;
    int select;
    do{
        printf("\nSelect menu:\n 1. Enqueue \t\t 2.Dequeue\n3.Display\t\t4.exit\n");
        scanf("%d",&select);
        switch (select)
        {
        case 1 :
            enqueue(&first, &last);
            break;
        case 2 :
            dequeue(&first, &last);
            break;
        case 3 :
            display(&first);
            break;
        case 4:
            printf("Operation Complete!!!");
            select = 0;
            break;
        default:
            printf("Invalid Option!!!");
            continue;
        }

    }while(select!=0);


    return 0;
}