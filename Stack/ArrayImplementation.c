#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1)
    return 1;
    else
    return 0;
}
int isEmpty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int data){
    if(isFull()){
        printf("Stack overflow");
        return;
    }
    top =top+1;
    stack_arr[top] =data;
}


int pop(){
    int value;
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    value=stack_arr[top];
    top =top-1;
    return value;
}
int peek(){
    if(isEmpty()){
        printf("Stack underflow \n");
        exit(1);
    }
    return stack_arr[top];
}
void display(){
    int i;
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    for(i=top;i>=0;i--){
        printf("%d ",stack_arr[i]);
        printf("\n");
    }
}
int main(){
    int data,choice;
    while(1){
        printf("\n");
        printf("1. Pushing\n");
        printf("2. Pop\n");
        printf("3. Print the top element \n");
        printf("4. Print all the element of the stack\n ");
        printf("5. Quit\n");
        printf("Please enter your choice :");
        scanf("%d ",&choice);
     
    
    switch(choice){
    case 1:
        printf("Enter the element to be pushed :");
        scanf("%d ",&data);
        push(data);
        break;
    
    case 2:
       data =pop();
       printf("Deleted element is %d \n", data);
       break;
    
    case 3:
       printf("The topmost element of the stack is %d ",peek());
       break;
    case 4 :
       display();
       break;
    case 5:
       exit(1);
    default :
       printf("Wrong choice\n");

  }

}
//    push(1);
//    push(2);
//    push(3);
//    push(4);
//    push(5);
//    data = pop();
//    data =pop();
//    display();
   return 0;
}