#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;

};
struct node * head,*tail;

void creat_node(int value){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link =NULL;

    if(head == NULL){
      head = newNode;
      tail= newNode;
    }
    else{
        tail->link =newNode;
        tail =newNode;
    }
}
void add_at_end(struct node *head ,int value){
    struct node *ptr,*temp;
    ptr =head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link =NULL;

    printf("Linked list after adding nodes at last :\n");
    printf(" %d " ,ptr->data);
    while (ptr->link != NULL){
        ptr =ptr->link;
        printf(" %d ", ptr->data);
        
    }
    ptr->link =temp;
    printf("%d" ,temp->data);
   
   
   


}
int main(){
     
      int number, value;
    printf("Enter the number of nodes :");
    scanf("%d",&number);
   
    printf("Enter the value of nodes :");
    for(int i =0;i<number;i++){
       scanf("%d",&value);
       creat_node(value);
    }

    add_at_end(head,67);
}