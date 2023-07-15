#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
   int lchild;
   int rchild;
   int info;
};
struct node *stack[MAX];
int top =-1;
void push_stack(struct node *item){
    if(top == (MAX-1)){
        printf("\nStack overflow");
        return ;
    }
    top =top+1;
    stack[top] =item;
}
struct node *pop_stack(){
    struct node *item;
    if(top==-1){
        printf("\nStack Underflow");
        exit(1);
    }
    item =stack[top];
    top=top-1;
    return item; 
}

int stack_empty(){
    if(top ==-1)
      return 1;
    else 
      return 0;
}
void nrec_pre(struct node *root){
    struct node *ptr =root;
    if(ptr ==NULL){
        printf("\nTree is empty ");
        return ;
    }
    push_stack(ptr);

    while(!stack_empty()){
        ptr = pop_stack();
        printf("%d ",ptr->info);

        if(ptr->rchild !=NULL)
          push_stack(ptr->rchild);
        
        if(ptr->lchild !=NULL)
          push_stack(ptr->lchild);

    }
    printf("\n");
}

void nrec_in(struct node *root){
    struct node *ptr =root;

    if(ptr ==NULL){
        printf("\nTree is empty");
        return ;
    }
    while(1){
        while(ptr->lchild !=NULL){
            push_stack(ptr);
            ptr =ptr->lchild;
        }
        while(ptr->rchild == NULL){
            printf("%d  ",ptr->info);

            if(stack_empty())
              return ;
            ptr =pop_stack();
        }
        printf("%d ",ptr->info);
        ptr =ptr->rchild;
    }
    printf("\n");
}

void nrec_post(struct node *root){
    struct node *q, *ptr = root;

    if(ptr == NULL){
        printf("\nTree is empty ");
        return ;
    }
    q =root;
    
    while(1){
        while(ptr->lchild !=NULL){
            push_stack(ptr);
            ptr =ptr->lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild ==q){
            printf("%d ",ptr->info);
            q =ptr;
            if(stack_empty())
             return ;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
}

int main(){
    
}