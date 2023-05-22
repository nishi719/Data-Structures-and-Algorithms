#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *add_to_empty(struct node *head ,int data){
    struct node *temp;
    temp = (struct node * )malloc(sizeof(struct node ));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    head =temp;
    return head;
}
struct node* add_to_end(struct node *head ,int data){
    struct node *temp,*ptr;
    temp =(struct node *)malloc(sizeof(struct node ));
    temp->prev =NULL;
    temp->data =data;
    temp->next=NULL;
    ptr =head;
    while(ptr->next != NULL)
    ptr=ptr->next;

    ptr->next=temp; 
    temp->prev =ptr;
    return head;
}
struct node *create_list(struct node *head){
   int i,n,data;
   printf("Enter the number of nodes");
   scanf("%d ",&n);
  
   if(n==0)
   return head;

   printf("Enter the element for the node 1 :");
   scanf("%d ",&data);
   head = add_to_empty(head ,data);

   for(i=1;i<n;i++){
    printf("Enter the element for the node %d :", i+1);
    scanf("%d ",&data);
    head = add_to_end(head ,data); 

   }
   return head;
}

int main(){
   struct node* head =NULL;
   struct  node* ptr;
   
   head =create_list(head);
   ptr =head;
   while(ptr != NULL){
      printf("%d ", ptr->data);
      ptr =ptr->next;
   }
   return 0;
  
}