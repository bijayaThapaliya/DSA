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
void push(node **top){
    int val;
    node *temp;
    temp=getNode();
    printf("Enter the value to push??");
    scanf("%d",&val);
    temp->data=val;
    temp->next=NULL;
    if((*top)==NULL){
        (*top)=temp;
    }
    else{
        temp->next=*top;
        (*top)=temp;
    }
}

void pop(node **top){
    node * temp;
    if(*top==NULL){
        printf("Stack Underflow!!!");
    }
    else{
        temp=(*top);
        printf("%d is deleted", temp->data);
        *top=temp->next;
        free(temp);
    }
}
void display(node **top){
    node * temp;
    if((*top)==NULL){
        printf("Stack Underflow");
    }
    else{
        temp=(*top);
        while(temp->next!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main(){
    node *top;
    top=NULL;
    int select;
    do{
        printf("\nSelect menu:\n 1. Push \t\t 2.Pop\n3.Display\t\t4.exit\n");
        scanf("%d",&select);
        switch (select)
        {
        case 1 :
            push(&top);
            break;
        case 2 :
            pop(&top);
            break;
        case 3 :
            display(&top);
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