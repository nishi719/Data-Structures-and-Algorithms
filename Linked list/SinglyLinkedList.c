#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
 struct node *head =NULL;
 struct node *create_node(struct node *head);
 void display(struct node *head);
 void count(struct node *head);
 void search(struct node *head , int data);
 struct node *add_at_beg(struct node *head ,int data);
 struct node *add_at_end(struct node *head ,int data);
 struct node *add_after(struct node *head ,int data ,int item);
 struct node *add_before(struct node *head ,int data ,int item);
 struct node *add_at_pos(struct node *head ,int data ,int item);
 struct node *del_at_beg(struct node *head ,int data);
 struct node *del_at_last(struct node *head ,int data);
 struct node *del_at_pos(struct node *head ,int data ,int item);
 struct node *reverse(struct node *head);


int main(){
    int choice,pos,value,item;
    while(1){
        printf("1.Create list \n");
        printf("2.Display \n");
        printf("3.Count \n");
        printf("4.Search \n");
        printf("5.Add to empty list \n");
        printf("6.Add at the end \n");
        printf("7.Add after the node \n");
        printf("8.Add before the node \n");
        printf("9.Add at any position \n");
        printf("10.Delete from beginning \n");
        printf("11.Delete from end \n");
        printf("12.Delete from any postion in between \n");
        printf("13.Reverse \n");
        printf("14.Quit\n\n");
        scanf("%d ",&choice);

        switch(choice){
         case 1:
            head =  create_node(head);
            break;
         case 2:
            display(head);
            break;
         case 3:
            count(head);
            break;
         case 4:
            printf("Enter the element to be searched :");
            scanf("%d ",&value);
            search(head,value);
            break;
         case 5:
            printf("Enter the element to be inserted :");
            scanf("%d ",&value);
            head = add_at_beg(head ,value);
            break;
         case 6:
            printf("Enter the value to be inserted :");
            scanf("%d ",&value);
            head = add_at_end(head ,value);
            break;
         case 7:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            head = add_after(head ,value,item);
            break;
         case 8:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            head = add_before(head ,value,item);
            break;
         case 9:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            head = add_at_pos(head ,value,pos);
            break;
         case 10:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            head = del_at_beg(head,value);
            break;
         case 11:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            head = del_at_last(head,value);
            break;
         case 12 :
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            printf("Enter the postion from which element to be deleted");
            scanf("%d" ,&pos);
            head = del_at_pos(head,value,pos);
            break;
         case 13 :
            head = reverse(head);
            break;
         case 14 :
            exit(1);
         default:
           printf("Wrong choice\n");    

        }
    }
    
}
struct node * create_node(struct node *head){
    int i,n,data;
    printf("Enter the number of nodes :");
    scanf("%d ",&n);
    head = NULL;
    if(n==0)
    return head;

    printf("Enter the element to be inserted :");
    scanf("%d" ,&data);
    head = add_at_beg(head ,data);
    for(i =2 ; i<=n ;i++){
        printf("Enter the element to be inserted :");
        scanf("%d",&data);
        head = add_at_end(head ,data);
    }
    return head;
}
void display(struct node *head){
    struct node *ptr ;
    if(head ==NULL){
        printf("List is empty");
        return;
    }
    ptr =head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr =ptr->link;
    }
    printf("\n\n");
}
void count(struct node * head){
    int count =0;
    struct node *ptr;
    ptr =head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("Number of nodes are %d " , count);
}
void search(struct node *head , int data){
    struct node * ptr =head;
    int pos =1;
    while(ptr != NULL){
        if(ptr->link == data){
            printf("Item %d found at position %d \n ", data , pos);
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    printf("Item %d is not found in list ",data);
}