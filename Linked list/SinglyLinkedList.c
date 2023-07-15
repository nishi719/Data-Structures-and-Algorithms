#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
}*head =NULL;
 
void create_node(struct node* head ){
    int n;
    printf("Enter the value to be inserted : ");
    scanf("%d",&n);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->link = NULL;
    if(head == NULL){
        head = new_node;
        return;
        }
        struct node *temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new_node;
        return;
       

}

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
            create_node(head);
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
            search(head ,value);
            break;
         case 5:
            printf("Enter the element to be inserted :");
            scanf("%d ",&value);
            add_at_beg(head ,value);
            break;
         case 6:
            printf("Enter the value to be inserted :");
            scanf("%d ",&value);
            add_at_end(head ,value);
            break;
         case 7:
            // printf("Enter the element to be inserted :");
            // scanf("%d", &value);
            // printf("Enter the element after which to insert :");
            // scanf("%d ",&item);
            // head = add_after(head ,value,item);
            break;
         case 8:
            // printf("Enter the element to be inserted :");
            // scanf("%d", &value);
            // printf("Enter the element after which to insert :");
            // scanf("%d ",&item);
            // head = add_before(head ,value,item);
            break;
         case 9:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            add_at_pos(head ,value,pos);
            break;
         case 10:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            del_at_beg(head);
            break;
         case 11:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            del_at_end(head);
            break;
         case 12 :
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            printf("Enter the postion from which element to be deleted");
            scanf("%d" ,&pos);
             del_at_pos(head,pos);
            break;
         case 13 :
            reverse(head);
            break;
         case 14 :
            exit(1);
            break;
         default:
           printf("Wrong choice\n");    

        }
    }
    
}