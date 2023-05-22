#include<stdio.h>
#define SIZE 100

int tree[SIZE];
void  initializeTree(){
    for(int i =0; i<SIZE ;i++)
    {
        tree[i] =-1 ; //-1 represent an empty node
    }
}
void insertNode(int value){
    int i=0;
    while(tree[i] != -1){
        if(value <tree[i]){
            i = 2*i +1 ; // go to the left child

        }
        else{
            i = 2*i +2 ; // go to the right child
        }
    }
    tree[i] =value;
}
void inorderTraversal(int index){
     if(index <SIZE && tree[index] != -1){
        inorderTraversal(2*index +1); // left child
        printf("%d ", tree[index]);
        inorderTraversal(2*index + 2); // right child
     }
}
int main(){
    initializeTree();
    
    // insertNode(4);
    // insertNode(2);
    // insertNode(6);
    // insertNode(8);
    // insertNode(2);

    int n,value;
    printf("\nEnter the number of nodes want to insert :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the %d node : " ,i+1);
        scanf("%d",&value);
        insertNode(value);
    }

    printf("Inorder traversal :");
    inorderTraversal(0);


    return 0;

}