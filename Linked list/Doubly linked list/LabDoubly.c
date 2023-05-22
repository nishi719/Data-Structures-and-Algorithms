#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;

};
struct node *head,*last;
void createList(int n){
    int i, data;
    struct node *newNode;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
         if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if(newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; 
                    newNode->next = NULL;

                    last->next = newNode; 
                    last = newNode;          
                }
                else{
                    printf("Unable to allocate memory.");
                    break;
                }
            }
    }
        else{
            printf("Unable to allocate memory");
        }
    }
}
struct node* add_beg(struct node* head ,int data){
    struct node * temp =malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next =head;
    temp->prev=temp;
    head=temp;

    return head;
}
struct node* add_end(struct node* head ,int data){
    struct node *temp = malloc(sizeof(struct node));
    struct node* ptr;
    temp->data=data;
    temp->prev =NULL;
    temp->next =NULL;
    ptr =head;

    while (ptr->next != NULL)
      ptr =ptr->next;

       ptr->next =temp;
       temp->prev =ptr;

       return head;
 
};

struct node * add_between(struct node * head ,int data,int value){
    struct node *ptr = malloc(sizeof(struct node));

    ptr->data =data;
    struct node *temp1 ,*temp2;
    temp1 =head;
    
    while(temp1->data != value)
        temp1 =temp1->next;
        temp2=temp1->next;
        ptr->next =temp2;
        temp1->next =ptr;
        ptr->prev =temp1;
  
       return head;

    
}
struct node* delFirst(struct node *head){
    struct node* temp=head;
    head =head->next;
    free(temp);
    temp =NULL;
    head->prev =NULL;
    return head;
}
struct node* delLast(struct node* head){
    struct node* temp =head;
    struct node* temp2;
    while(temp->next != NULL)
      temp =temp->next;
    temp2 =temp->prev;
    temp2->next =NULL;
    free(temp);
    return head;
}
struct node* delInter(struct node* head ,int pos){
    struct node* temp =head;
    struct node* temp2 =NULL;

    if(pos ==1){
        head =delFirst(head);
        return head;
    }
    while(pos>1){
        temp =temp->next;
        pos--;
    }
    if(temp->next ==NULL)
    head =delLast(head);
    else{
        temp2 =temp->prev;
        temp2->next =temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp =NULL;
    }
    return head;
}
struct node* reverse(struct node* head){
    struct node* ptr1 =head;
    struct node* ptr2 =ptr1->next;
    ptr1->next =NULL;
    ptr1->prev =ptr2;

    while(ptr2 != NULL){
        ptr2->prev =ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2 =ptr2->prev;
    }
    head =ptr1;
    return head;
}
void display(struct node *head){
    struct node* ptr=head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr =ptr->next;
    }
    printf("\n");
}
void Forward_traversal(struct node *head){
    
    struct node * ptr=head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr =ptr->next;
    }  
}
void Backward_traversal(struct node *head){
    struct node* ptr=head;
    while(ptr->next != NULL){
        ptr =ptr->next;
    }
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }

}


int main(){
    int n;
    head =NULL;
    last =NULL;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    createList(n);

    display(head);
    printf("\nForward traversal in list : ");
    Forward_traversal(head);

    printf("\nBackward traversal in list :");
    Backward_traversal(head);

    printf("\nList after inserting at beginning :");
    head = add_beg(head ,100);
    display(head);

    printf("\nList after inserting at end :");
    head = add_end(head ,100);
    display(head);

    printf("\nList after inserting in between :");
    head =add_between(head ,100,100);
    display(head);

    printf("Before reverse :");
    display(head);

    printf("After reversing :");
    head =  reverse(head);
    display(head);
    printf("Before deletion : ");
  
    display(head);

   printf("\nDeletion at beg :");
   head =delFirst(head);
   display(head);

   printf("\nDeletion at last :");
   head = delLast(head);
   display(head);

   printf("\nDeletion at index 2 :");
   head = delInter(head,2);
   display(head);
   
   printf("After deletion :");
   display(head);

   
}
