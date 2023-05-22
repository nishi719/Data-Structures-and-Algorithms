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
    printf("Array elements are :\n");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}