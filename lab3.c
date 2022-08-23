#include <stdio.h>
#define MAX 3
#define TRUE 1
#define FALSE 0


struct Queue
{
    int rear;
    int front;
    int data[MAX];

};

int isEmpty(struct Queue*q){
    return((q->front==q->rear)?TRUE:FALSE);
}    
int isFull(struct Queue*q){
    return((q->rear+1==q->front)?TRUE:FALSE);
}

// int isEmpty(struct Queue*q){
//     if(q->front>q->rear)
//         return 1;
//     else
//         return 0;
// }
// int isFull(struct Queue*q){
//     if(q->rear==MAX-1)
//         return 1;
//     else
//         return 0;
//     }

void enqueue(struct Queue*q){
    int eltAdd;
    if(isFull(q)){
        printf("Queue is Full.\n");
    
    }
    else{
        printf("Enter the element your want to add:\n");
    scanf("%d",&eltAdd);
    q->rear=(q->rear+1)%MAX;
    q->data[q->rear]=eltAdd;
    printf("%d is added to Queue\n",eltAdd);

    }
    

}
void dequeue(struct Queue*q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    
    }
    else{
        q->front++;
        printf("%d is removed\n",q->data[q->front]);
    

    }
    
}
void display(struct Queue*q){
    int i;
    if(isEmpty(q)){
        printf("Queue is empty\n");
        
    }   
    else{
    printf("Current Element is Queue\n");
   
    for(i=(q->front+1)%MAX; i!=q->rear;i=(i+1)%MAX){
    
        printf("%d\t",q->data[i]);

    }
    printf("%d\t",q->data[i]);
    }
}
int main(){
    int exit=1, menu;
    struct Queue q;
    q.front=q.rear=MAX-1;
    
    do{
        
        printf("\n************\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n************\n");
        printf("\nSelect the opreation you want to perfrom\n");
        scanf("%d",&exit);
        switch(exit){
            case 1:
            enqueue(&q);
            break;
            case 2:
            dequeue(&q);
            break;
            case 3:
            display(&q);
            break;
            case 4:
            printf("\nQueue operation complete!!!");
            exit=4;
        }
    }while(exit!=4);

    
    return 0;
    
}