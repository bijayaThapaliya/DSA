#include <stdio.h>
#define max 4
struct Stack
{
    int top;
    int a[max];

};
void push(struct Stack*s){
    int num;
    if(s->top==max-1){
        printf("Stack is full\n");
    }
    else{

        s->top=s->top+1;
        printf("Enter the number you want to add.\n");
        scanf("%d",&num);
        s->a[s->top]=num;
        printf("%d is added to your stack\n",num);
    }
}

void pop(struct Stack*s){
    int rem;
    if(s->top==-1){
         printf("Stack is empty\n");
    }
    else{
        rem=s->a[s->top];
        printf("%d is poped",rem);
        s->top=s->top-1;
    }
}
void display(struct Stack*s){
    int i,b;
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack Details:\n");
        printf("**************\n");
        for(i=s->top;i>=0;i--){
            b=s->a[i];
            printf("%d\n",b);
        }
    }
}

int main(){
    int optn;
    struct Stack s;
    s.top=-1;
    char ch='y';
    while(ch=='Y'||ch=='y'){
    printf("Select the option\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&optn);
   
    switch (optn)
    {
    case 1:
        push(&s);
        break;
    case 2:
        pop(&s);
        break;
    case 3:
        display(&s);
        break;    
    
    default:
        goto end;
        break;
    }
    fflush(stdin);
    printf("Would you like to continue\n");
    scanf("%c",&ch);
}
end:
printf("\nStack operation completed!");
return 0;
}