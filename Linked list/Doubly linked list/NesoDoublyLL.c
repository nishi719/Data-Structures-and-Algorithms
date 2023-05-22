#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *addToEmpty(struct node *head ,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data =data;
    temp->next =NULL;
    head =temp;
    return head;
};
struct node * addToBeg(struct node *head ,int data){
    struct node *temp =malloc(sizeof(struct node));
    temp->prev =NULL;
    temp->data =data;
    temp->next =NULL;
    temp->next =head;
    head->prev = temp;
    head =temp;
    
    return head;
};
struct node *addToEnd(struct node *head ,int data){
    struct node *ptr,*temp;
    temp =malloc(sizeof(struct node ));
    temp->data =data;
    temp->next =NULL;
    temp->prev =NULL;
    ptr =head;
    while(ptr->next !=NULL)
    ptr =ptr->next;

    ptr->next=temp;
    temp->prev =ptr;
    return head;
};
struct node * addAtPos(struct node *head ,int data ,int pos){
    struct node *newPos =NULL;
    struct node *temp = head;
    struct node * temp2 =NULL;
    newPos = addToEmpty(newPos ,data);

    // while (pos !=1){
    //     temp =temp->next;
    //     pos--;
    // }
    // if(temp->next ==NULL){
    //     temp->next =newPos;
    //     newPos->prev =temp;
    // }
    // else{
    // temp2 = temp->next;
    // temp->next =newPos;
    // temp2->prev =newPos;
    // newPos->next=temp2;
    // newPos->prev =temp;

    // }

    int p =pos;
    while(p>2){
        temp =temp->next;
        p--;
    }
    if(pos==1){
        head=addToEmpty(head,data);
    }
    else{
    temp2 = temp->next;
    temp->next =newPos;
    temp2->prev =newPos;
    newPos->next=temp2;
    newPos->prev =temp;

    }
    return head;
    
};
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
void display(struct node* head){
    struct node* ptr =head;
    while(ptr != NULL){
       printf("%d ", ptr->data);
       ptr=ptr->next;
    }
    printf("\n");
}
int main(){
   struct node *head =NULL;
   int position =3;
   head = addToEmpty(head,45);
   head = addToBeg(head ,34);
   head = addToEnd(head ,9);
   head =addAtPos(head,30,position);
  
   
//    printf("Before deletion : ");
//    display(head);

//    head =delFirst(head);
//     head = delInter(head,2);
//    printf("After deletion :");
//    display(head);

    printf("Before reverse :");
    display(head);

    printf("After reversing :");
    head =  reverse(head);
    display(head);
   
   return 0;
}