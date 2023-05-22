#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
// create a node 
struct node* create(int data)
{
    struct node* newNode = malloc(sizeof(struct node*));
    if(newNode == NULL)
    {
        printf("\nMemory allocation failed");
        exit(1);
    }
    newNode->data =data;
    newNode->left =NULL;
    newNode->right =NULL;

    return newNode;
};
// insert a node into the binary tree
struct node* insert(struct node* root ,int data){
    if(root == NULL){
        root = create(data);
    }
    else if(data <= root->data)
    {
        root->left =insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }

    return root;
}
void preorderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}
void postorderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ",root->data);
}
int main(){
    struct node* root =NULL;
   
    int n,value;
    printf("\nEnter no of nodes want to create :");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the value of %d node :" ,i+1);
        scanf("%d",&value);
        root = insert(root ,value);
    }

    printf("\nPreorder traversal :");
    preorderTraversal(root);

    printf("\nInorder traversal :");
    inorderTraversal(root);

    printf("\nPostorder traversal :");
    postorderTraversal(root);


    

    return 0;
}