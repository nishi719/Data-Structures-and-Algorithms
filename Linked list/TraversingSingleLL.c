#include<stdio.h>
#include<stdlib.h>
struct node{
 int  data;
 struct node *link;
};
struct node *head, *tail;
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
void count_of_node(struct node *head){
    int count =0;
    // if(head ==NULL);
    // printf("Linked list is empty");
    struct node *ptr =NULL;
    ptr =head;
    while(ptr !=NULL){
        count++;
        ptr= ptr->link;
    }
    printf("Total number of nodes  : %d",count);
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

    count_of_node(head);
}