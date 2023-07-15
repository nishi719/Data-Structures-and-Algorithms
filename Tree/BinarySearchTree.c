#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};
struct node* newNode(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
    }
struct node* insert(struct node* root, int x){
    if(root == NULL){
         return newNode(x);
             }
    if(x < root->data){
       root->left = insert(root->left, x);
        }
    else if(x > root->data){
         root->right = insert(root->right, x);
        }
        return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root =NULL;
    root = insert(root ,10);
    insert(root ,30);
    insert(root ,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    insert(root,90);
    insert(root,100);

    printf("Binary search tree :\n");
    inorder(root);
    return 0;
}


