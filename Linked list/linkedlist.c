#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}* head =NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    printf("\nNode created successfully\n");
    return newNode;

}
void count(struct Node* head){
  int count=0;
  struct Node * ptr;
  ptr =head;
  if(head == NULL)
   printf("List is empty");

   while(ptr !=NULL){
    count++;
    ptr = ptr->next;
   }
   printf("Number of nodes in list are %d ", count);
}
void search(struct Node* head ,int value){

 struct Node * temp =head;
 while(temp != NULL){
    if(temp->data ==value)
    printf("Value is present ");

    temp =temp->next;
 }
  
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
    printf("Node inserted successfully at the beginning.\n");
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted successfully at the end.\n");
}
void insertAfterValue(struct Node* head, int value, int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted successfully after value %d.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the linked list.\n", value);
}
void insertBeforeValue(struct Node** head, int value, int data) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if ((*head)->data == value) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted successfully before value %d.\n", value);
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value %d not found in the linked list.\n", value);
        return;
    }
    prev->next = newNode;
    newNode->next = current;
    printf("Node inserted successfully before value %d.\n", value);
}

void insertAtPosition(struct Node** head, int position, int data) {
    if (*head == NULL && position != 1) {
        printf("Invalid position! Linked list is empty.\n");
        return;
    }
    if (position == 1) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted successfully at position %d.\n", position);
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    if (count < position) {
        printf("Invalid position! Linked list does not have %d nodes.\n", position);
        return;
    }
    struct Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = current;
    printf("Node inserted successfully at position %d.\n", position);
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted successfully from the beginning.\n");
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted successfully from the end.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted successfully from the end.\n");
}

void deleteValue(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with key %d deleted successfully.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with key %d deleted successfully.\n", key);
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("Linked list reversed successfully.\n");
}

void display(){
    struct Node *current =head;
    if(head ==NULL){
        printf("List is empty");
        return;
    }
    
    while(current != NULL){
        printf(" %d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void swapNodes(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sortLinkedList(struct Node* head) {
    if (head == NULL)
        return;

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swapNodes(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Linked list deleted successfully.\n");
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
        printf("13.Delete entire linked list \n");
        printf("14.Reverse \n");
        printf("15.Sorting of linked list \n");
        printf("16.Quit\n\n");
        printf("\n\nEnter you choice :");
        scanf("%d",&choice);

        switch(choice){
         case 1:
            printf("\nEnter the value to inserted :");
            scanf("%d",&value);
            head = createNode(value);
            break;
         case 2:
            display();
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
            insertAtBeginning(&head ,value);
            break;
         case 6:
            printf("Enter the value to be inserted :");
            scanf("%d ",&value);
            insertAtEnd(&head ,value);
            break;
         case 7:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            insertAfterValue(head ,value,item);
            break;
         case 8:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            insertBeforeValue(&head ,value,item);
            break;
         case 9:
            printf("Enter the element to be inserted :");
            scanf("%d", &value);
            printf("Enter the element after which to insert :");
            scanf("%d ",&item);
            insertAtPosition(&head ,pos,value);
            break;
         case 10:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            deleteFromBeginning(&head);
            break;
         case 11:
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            deleteFromEnd(&head);
            break;
         case 12 :
            printf("Enter the element to be deleted :");
            scanf("%d",&value);
            printf("Enter the value to be deleted");
            scanf("%d",&pos);
            deleteValue(&head,pos);
            display();
            break;
        case 13:
            deleteList(&head);
            display();
            break;
              
         case 14 :
            reverse(&head);
            display();
            break;
         case 15 :
         sortLinkedList(head);

        printf("Sorted linked list:\n");
        display();

        case 16 :
            exit(1);
            break;
            
         default:
           printf("Wrong choice\n");    

        }
    }
    return 0;
    
}
