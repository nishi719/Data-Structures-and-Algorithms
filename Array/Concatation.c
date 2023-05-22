#include<stdio.h>
int main(){
    int size1,size2;
    printf("Enter the size of first array :");
    scanf("%d",&size1);
    printf("Enter the size of second array :");
    scanf("%d",&size2);
    int arr1[size1], arr2[size2];
    int arr3[size1+size2];
    printf("Enter the element of first array :\n");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr1[i]);

    }
    printf("Enter the element of second array :\n");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr2[i]);

    }
    for(int i=0;i<size1;i++){
        arr3[i]=arr1[i];
    }
    for(int i=0 ,j =size1;i<size2;i++,j++){
        arr3[j]=arr2[i];
    }
    printf("Array element after concatenation :\n");
    for(int i=0;i<size1+size2;i++){
        printf("%d ",arr3[i]);
    }
}