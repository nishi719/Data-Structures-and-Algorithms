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
    printf("Array elements before deletion are :\n");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    
    int pos;
    printf("\nEnter the postion of element to be deleted :");
    scanf("%d",&pos);

    if(pos<1 || pos>size)
    {
        printf("Invalid position ");
    }
    else{
        for(int i=pos-1;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    

    }
    printf("\nArray element after deletion :\n");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}