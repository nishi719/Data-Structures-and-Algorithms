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
void display(){
    struct node *current =head;
    if(head ==NULL){
        printf("List is empty");
        return;
    }
    printf("Nodes of singly list : \n");
    while(current != NULL){
        printf(" %d ",current->data);
        current = current->link;
    }
    printf("\n");
}
int main(){
   
//    head = (struct node *)malloc(sizeof(struct node));
//    head->data =50;
//    head->link = NULL;
  
   
//    struct node *current = (struct node *)malloc(sizeof(struct node));
//    current->data = 60;
//    head->link = current;
//    current->link=NULL;

//    struct node *current2 = (struct node *)malloc(sizeof(struct node));
//    current2->data =80;
//    current->link = current2;
//    current2->link =NULL;

    //  current = malloc(sizeof(struct node));
    //  current->data = 90;
    //  current->link =NULL;

    //  head->link->link = current;


    

    int number, value;
    printf("Enter the number of nodes :");
    scanf("%d",&number);
   
    printf("Enter the value of nodes :");
    for(int i =0;i<number;i++){
       scanf("%d",&value);
       creat_node(value);
    }
    
    display();

   

    return 0;
}