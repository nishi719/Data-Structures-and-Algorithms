#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front =NULL ,*rear =NULL;

void insert(int item);
int del();
int peek();
int isEmpty();
void display();

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

void insert(int item)
{
    struct node* temp;
    temp =(struct node*)malloc(sizeof(struct node));
    if(temp ==NULL)
    {
        printf("\nMemory not available\n");
        return;
    }
    temp->data =item;
    temp->link =NULL;

    if(front ==NULL)
       front =temp;
    else
      rear->link =temp;

    rear =temp;

    printf("\nElement inserted in queue \n");
}

int del()
{
    struct node *temp;
    int item;
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    temp =front;
    item =temp->data;
    front =front->link;
    free(temp);

    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("\nQueue underflow\n");
        exit(1);
    }
    return front->data;
}

int isEmpty(){
    if(front ==NULL)
      return 1;
    else
      return 0;
}

void display(){
    struct node *ptr;
    ptr =front;

    if(isEmpty())
    {
        printf("\nQueue is empty \n");
    }
    printf("\nQueue element :\n");
    while(ptr != NULL)
    {
        printf("%d " ,ptr->data);
        ptr =ptr->link;
    }
    printf("\n\n");
}

