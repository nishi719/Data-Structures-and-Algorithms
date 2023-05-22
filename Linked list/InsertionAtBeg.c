#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head ,*tail;
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
void add_at_beg(struct node *head ,int value){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data =value;
    ptr->link= NULL;

    ptr->link = head;
    head =ptr;

   printf("Linked list after inserting a nodes at beginning :");
   while(ptr != NULL){
    printf("%d ", ptr->data);
    ptr =ptr->link;
   }
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
  add_at_beg(head,20);
}