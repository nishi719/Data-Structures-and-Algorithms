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
    printf("\nArray elements before reversal are :\n");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    int temp;
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("\nArray elements after reversal are :\n");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}