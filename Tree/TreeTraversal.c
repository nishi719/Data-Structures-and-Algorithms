#include<stdio.h>
#include<stdlib.h>
struct treenode{
      int data;
      struct treenode* left;
      struct treenode* right;
};

struct treenode* insertdata(int data){
    struct treenode *root = malloc(sizeof(struct treenode*));
    root->data =data;
    root->left =NULL;
    root->right =NULL;
    return root;


}
void inorder(struct treenode* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct treenode* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct treenode* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct treenode* root = malloc(sizeof(struct treenode*));

    root =insertdata(10);
    root->left =insertdata(20);
    root->right =insertdata(30);
    root->left->left =insertdata(40);
    root->right->right =insertdata(50);
    root->left->right =insertdata(60);
    root->right->left =insertdata(70);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);


    return 0;


}