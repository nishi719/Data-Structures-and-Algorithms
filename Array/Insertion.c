#include<stdio.h>

int main(){
    int size;
    printf("Enter the size of array :");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the element of array :\n");
    for(int i=0;i<size;i++){
       scanf("%d",&arr[i]);
    }
    int pos;
    printf("Enter the position array to be added :");
    scanf("%d",&pos);
    int element;
    printf("Enter the element to be inserted :");
    scanf("%d",&element);
    for(int i=size ;i>pos;i--)
        arr[i]==arr[i-1];
    
    arr[pos]=arr[element];
    printf("Array after insertion :\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}