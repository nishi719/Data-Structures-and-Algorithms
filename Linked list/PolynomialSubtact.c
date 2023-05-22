#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node* next;
};

void insert(struct node** head, int coeff, int power)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->power = power;
    new_node->next = (*head);
    (*head) = new_node;
}

void display(struct node* head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->power);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
}

void polySubtraction(struct node** result, struct node* poly1, struct node* poly2)
{
    struct node *temp1 = poly1, *temp2 = poly2;
    while (temp1 && temp2)
    {
        if (temp1->power == temp2->power)
        {
            insert(result, temp1->coeff - temp2->coeff, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power)
        {
            insert(result, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        }
        else
        {
            insert(result, -temp2->coeff, temp2->power);
            temp2 = temp2->next;
        }
    }
    while (temp1)
    {
        insert(result, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }
    while (temp2)
    {
        insert(result, -temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }
}

int main()
{
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    insert(&poly1, 5, 2);
    insert(&poly1, 4, 1);
    insert(&poly1, 2, 0);

    insert(&poly2, 5, 1);
    insert(&poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("\nPolynomial 2: ");
    display(poly2);

    polySubtraction(&result, poly1, poly2);
    printf("\nResultant polynomial after subtraction: ");
    display(result);

    return 0;
}