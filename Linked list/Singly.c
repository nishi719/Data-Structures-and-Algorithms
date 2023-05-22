#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;

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
void traversal(struct node* head){
  int count=0;
  struct node * ptr;
  ptr =head;
  if(head == NULL)
   printf("List is empty");

   while(ptr !=NULL){
    count++;
    ptr = ptr->link;
   }
   printf("Number of nodes in list are %d ", count);
}
void add_at_beg(struct node* head ,int data){
    struct node* temp =malloc(sizeof(struct node));
    temp->data =data;

   temp->link =head;
   head =temp;

   while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->link;
   }   
}
void add_at_end(struct node * head ,int data){
    struct node* temp =malloc(sizeof(struct node));
    temp->data =data;
    temp->link =NULL;

    struct node* ptr;
    ptr =head;
    while(ptr->link != NULL){
        ptr =ptr->link;
    }
    ptr->link=temp;

}
void add_at_pos(struct node* head ,int data ,int position){
    struct node* temp =malloc(sizeof(struct node ));
    temp->data =data;
    struct node* ptr1;
    ptr1 =head;
    position--;
    while(position != 1){
        ptr1 =ptr1->link;
        position--;
    }
    temp->link =ptr1->link;
    ptr1->link =temp;

    struct node* ptr2;
    ptr2 =head;
    while(ptr2 !=NULL){
        printf("%d ",ptr2->data);
        ptr2 = ptr2->link;
    }

}
void del_at_beg(struct node* head){
    //struct node* temp=malloc(sizeof(struct node));
    struct node* temp;
    temp =head;
    head =head->link;
    free(temp);

    struct node* ptr;
    ptr =head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr =ptr->link;
    } 
}
void del_at_end(struct node* head){
    
        struct node *temp=malloc(sizeof(struct node));
        temp=head;
        struct node *temp2=malloc(sizeof(struct node));
        while(temp->link !=NULL){
            temp2 =temp;
            temp =temp->link;
        }
        temp2->link =NULL;
        free(temp);

     struct node* ptr;
     ptr=head;
     while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr =ptr->link;
     }
}
void del_at_pos(struct node * head ,int position){
    struct node* temp1 =head;
    struct node* temp2 =head;
    while(position != 1){
        temp2 =temp1;
        temp1 =temp1->link;
        position--;
    }
    temp2->link =temp1->link;
    free(temp1);

    struct node* ptr;
     ptr=head;
     while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr =ptr->link;
     }


}
void search(){
 int value =34;
 struct node * temp =head;
 while(temp != NULL){
    if(temp->data ==value)
    printf("Value is present ");

    temp =temp->link;
 }
  
}
// void concat(){
//     struct node* head1 =malloc(sizeof(struct node));
//     struct node* temp ;
//     temp =head;
//     while(temp->link != NULL){
//         temp=temp->link;
//         temp->link=head1;
//     }
//     struct node* ptr ;
//     ptr =head;
//     while(ptr != NULL){
//         printf("%d ",ptr->data);
//         ptr =ptr->link;
//     }
// }
void swap(){
    int temp ;
    int a,b;
    a =temp;
    a =b;
    temp=b;
}
void sorting(struct node *head){
    struct node* temp =malloc(sizeof(struct node));
    temp =head;
    struct node* ptr;
    while(temp->link != NULL){
       ptr =temp->link;

       while(ptr != NULL)
       if(ptr->data < temp->data)
       swap();
    }
    temp =temp->link;
}
void reverse(struct node* head){
    struct node *ptr,*temp1,*temp2;
    ptr =head;
    temp1 =NULL;
    while(ptr != NULL){
        temp2 =ptr->link;
        ptr->link =temp1;
        temp1 =ptr;
        ptr=temp2;
    }
    head =temp1;

    struct node *rev;
    rev =head;
    while(rev !=NULL){
        printf("%d ",rev->data);
        rev=rev->link;
    }
}
void display(){
    struct node *current =head;
    if(head ==NULL){
        printf("List is empty");
        return;
    }
    
    while(current != NULL){
        printf(" %d ",current->data);
        current = current->link;
    }
    printf("\n");
}
int main(){
   

    int number, value,item;
    printf("Enter the number of nodes :");
    scanf("%d",&number);
   
    printf("Enter the value of nodes :");
    for(int i =0;i<number;i++){
       scanf("%d",&value);
       creat_node(value);
    }
    
    display();
    traversal(head);
    
    
    // printf("\nList after inserting element at beg :");
    // add_at_beg(head,100);
    // printf("\nList after inserting element at end :");
    // add_at_end(head ,100);
    // display();
    // printf("\nList after inserting element in between :");
    // add_at_pos(head ,100,3);
    // printf("\nList after deleting element at beg :");
    // del_at_beg(head);
    // printf("\nList after deleting element from end :");
    // del_at_end(head);
    // printf("\nList after deleting element in between :");
    // del_at_pos(head,3);
    // search();    
    // concat();
    // sorting(head);
    reverse(head);
    

   

    return 0;
}