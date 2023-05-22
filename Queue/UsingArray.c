#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue_arr[MAX];
int rear =-1;
int front =-1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main(){
    int choice,item;

    while(1)
    {   
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display  element at the front\n");
        printf("4. Display all the element of the queue\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
              printf("\nEnter the element added in the queue :");
              scanf("%d",&item);
              insert(item);
              break;
            
            case 2:
              item =del();
              printf("\nDeleted element is %d\n ",item);
              break;
            
            case 3:
              printf("\nElement at the front is %d\n" ,peek());
              break;
            
            case 4:
               display();
               break;
            
            case 5:
               exit(1);
            default:
              printf("\nWrong choice .\n");

        }
    }
  return 0;
}
int isFull()
{
    if(rear ==MAX-1)
      return 1;
    else
      return 0;
}

int isEmpty()
{
    if(front ==-1 || front==rear+1)
       return 1;
    else  
       return 0;
}

void display()
{
    // int i;
    // if(isEmpty()){
    //     printf("\nQueue is empty\n");
    //     return;
    // }
    // printf("\nQueue is :\n");
    // for(i=front ;i<=rear ;i++)
    //   printf("%d  ",queue_arr[i]);
    
    // printf("\n\n");

    // 2nd method
   
      int i =front;
      printf("\nQueue is :\n");
      while(i != rear){
       printf("%d  ",queue_arr[i]);
       i++;
       }
       printf("%d  ",queue_arr[i]);

       printf("\n\n");


    
}

void insert(int item){
   if(rear == MAX-1){
    printf("\nQueue overflow.\n");
   }
   else{
    if(front ==-1)
     front =rear =0;
    else
     rear = rear+1;

   }
   queue_arr[rear] =item;

   printf("\nElement inserted in queue.\n\n");
}

int del(){
  int temp;
  
   
  if(front ==-1){
    printf("\nQueue underflow.\n");
  }
  else{
    temp =queue_arr[front];
    if(front== rear)
      front = rear =-1;
    else
      front =front+1;
    
  }
   return temp;
}

int peek(){
  if(isEmpty()){
    printf("\nQueue Underflow.\n");
    exit(1);
  }
  return queue_arr[front];
  
}