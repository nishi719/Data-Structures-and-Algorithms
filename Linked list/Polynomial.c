#include<stdio.h>
#include<stdlib.h>

struct node {
    float coefficient;
    int  exponent;
    struct node* link;
};

struct node* insert(struct node* head ,float co ,int ex)
{
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->coefficient =co;
    newP->exponent =ex;
    newP->link =NULL;

    if(head ==NULL || ex >  head->exponent)
    {
        newP->link =head;
        head =newP;
    }
    else{
        temp =head;
        while(temp->link != NULL && temp->link->exponent >= ex)
          temp =temp->link;
        newP->link =temp->link;
        temp->link =newP;
    }

    return head;
}
 

struct node* create(struct node* head)
{
    int n,i;
    float coeff;
    int expo;
    printf("\nEnter the number of terms:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient for term %d: ",i+1);
        scanf("%f" ,&coeff);

        printf("\nEnter the exponent for term %d: ",i+1);
        scanf("%d", &expo);

        head =insert(head ,coeff ,expo);

    }
    return head;

}

void display(struct node* head)
{
    if(head ==NULL)
      printf("\nNo polynomial");

    else{
        struct node* temp =head;
        printf("\nPolynomial :\n");
        while (temp != NULL)
        {
            printf("(%.1fx^%d)" , temp->coefficient , temp->exponent);
            temp = temp->link;

            if(temp != NULL)
              printf(" + ");
            else 
              printf("\n");
        }
        
    }
}
int main()
{
    struct node* head =NULL;
    printf("\nEnter the polynomial \n");
    head =create(head);
    display(head);

    return 0;

}