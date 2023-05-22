#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *prev;
   struct node *next;
};
struct node *head;
struct node *add_to_empty(struct node *head ,int data){
    struct node *temp;
    temp = (struct node * )malloc(sizeof(struct node ));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    head =temp;
    return head;
}
struct node * add_to_beg(struct node *head ,int data){
    struct node *temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev= NULL;
    temp->next =head;
    head->prev =temp;
    head = temp;

    return head;

}
struct node* add_to_end(struct node *head ,int data){
    struct node *temp,*ptr;
    temp =(struct node *)malloc(sizeof(struct node ));
    temp->data =data;
    ptr =head;
    while(ptr->next != NULL)
    ptr=ptr->next;

    ptr->next=temp;
    temp->next =NULL;
    temp->prev =ptr;
    return head;
}
struct node *create_list(struct node *head){
   int i,n,data;
   printf("Enter the number of nodes");
   scanf("%d ",&n);
//    head =NULL;
   if(n==0)
   return head;

   printf("Enter the element to be inserted :");
   scanf("%d ",&data);
   head = add_to_empty(head ,data);
   for(i=1;i<n;i++){
    printf("Enter the element to be inserted :");
    scanf("%d ",&data);
    head = add_to_end(head ,data);

   }
   return head;

}
void display(struct node *head){
    struct node *ptr;
    if(head ==NULL){
        printf("List is empty");
    }
    ptr =head;
    printf("List is :\n");
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr =ptr->next;
    }
    printf("\n");
}

int main(){
    
   head =create_list(head);
   display(head);
   int choice ,data,item;
   while(1){
    printf("1.Add to the empty list \n");
    printf("2.Add at the beginning \n");
    printf("Add at the end \n");
    printf("Enter your choice \n");
    scanf("%d ",&choice);
   }
   switch(choice){
    case 1:
    printf("Enter the element to be inserted :");
    scanf("%d ",&data);
    head =add_to_empty(head ,data);
    break;
    case 2:
    printf("Enter the element to be inserted :");
    scanf("%d ",&data);
    head =add_to_beg(head ,data);
    break;
    case 3:
    printf("Enter the element to be inserted :");
    scanf("%d ",&data);
    head =add_to_end(head ,data);
    break;
    
    default:
    printf("Wrong choice ");
   }
   display(head);
}