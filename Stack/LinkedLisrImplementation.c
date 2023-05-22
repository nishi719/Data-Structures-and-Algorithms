#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*top =NULL;

void push(int item){

    if(top == NULL){
        top = (struct node*)malloc(sizeof(struct node));
        top->link =NULL;
        top->data =item;
    
    }
    else{
    struct node* temp;
    temp =(struct node* )malloc(sizeof(struct node));
    temp->data = item;
    temp->link = top;
    top =temp;

    }
    printf("\nNode is Inserted\n\n");
    
}
int pop(){
    struct node* temp;
    temp =top;
    int item;
    if(temp ==NULL){
        printf("Stack Underflow");
        return -1;
    }
    else
      temp = temp->link;
      item = top->data;
      free(top);
      top = temp;
    
    return item;

}
int peek(){
    if(top==NULL){
        printf("Stack underflow ");
       return -1;
    }
    return top->data;

}

void display(){
    struct node* ptr;
    ptr =top;
    if(top==NULL){
        printf("Stack is empty\n");
        return ;
    }
    printf("Stack element :\n\n");
    while (ptr != NULL)
    {
       printf("%d--> " ,ptr->data);
       ptr =ptr->link;
    }
    printf("NULL\n\n");
}
int main(){
    int choice,item;
    printf("\nImplementation of Stack using linked list\n");
    while (1) {
        
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nEnter the item to be pushed :");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item =pop();
            printf("Popped item is : %d\n ",item);
            break;
        case 3:
            printf("Item at the top is %d\n ",peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default :
            printf("Wrong choice\n");

        }

    }

}

