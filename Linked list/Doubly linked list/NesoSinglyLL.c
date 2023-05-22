#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node* link;
};
void print_data(struct node* head){

    if(head =NULL)
    printf("Linked list is empty");
    struct node* ptr =NULL;
    ptr =head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr =ptr->link;
    }
    
}
void add_at_end(struct node* head ,int data){
    struct node *ptr,*temp;
    ptr =head;
    temp =malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link != NULL){
       ptr =ptr->link;
    }
    ptr->link =temp;
}
int main(){
     struct node* head;
     head =malloc(sizeof(struct node));
     head->data =10;
     head->link =NULL;
    //  printf("%d ",head->data);

    struct node* current;
    current = malloc(sizeof(struct node));
    current->data =30;
    current->link =NULL;
    head->link =current;

    current =malloc(sizeof(struct node));
    current->data=40;
    current->link =NULL;
    head->link->link =current;

    add_at_end(head,67);
    print_data(head);


    return 0;
}