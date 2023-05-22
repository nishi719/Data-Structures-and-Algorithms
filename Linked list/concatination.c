#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last_node = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void concatenate(struct node **head1_ref, struct node **head2_ref)
{
    struct node *ptr = *head1_ref;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = *head2_ref;
}

void displayList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 5);
    printf("List 1: ");
    displayList(head1);
    printf("\nList 2: ");
    displayList(head2);
    concatenate(&head1, &head2);
    printf("\nConcatenated list: ");
    displayList(head1);
    return 0;
}