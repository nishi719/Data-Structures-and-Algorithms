#include<stdio.h>

void swap(int *a ,int *b){
    int temp;
    temp = *a;
    *a =*b;
    *b =temp;
}
int partition(int arr[] ,int start ,int end){
    int pIndex =start;
    int pivot =arr[end];
    int i;

    for(i =start ;i <end ;i++){
        if(arr[i] <pivot){
            swap(&arr[i] ,&arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end] ,&arr[pIndex]);

    return pIndex;
}
void quickSort(int arr[] ,int start ,int end){
    if(start<end){
        int pIndex = partition(arr,start,end);
        quickSort(arr ,start ,pIndex-1);
        quickSort(arr,pIndex+1,end);
    }
}

int main(){
    int n,i;
    printf("\nEnter the array size \n");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter Array Elements\n");
    for(i=0;i<n;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);

    printf("\nAfter the QuickSort\n");

    for(i=0;i<n;i++)
       printf("%d ",arr[i]);
    printf("\n");

    return 0;
    
}
