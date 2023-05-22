#include<stdio.h>
int largest(int arr[],int size){
    int largest =arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}
int main(){
    int arr[]={10,5,20,8,15};
    int size = sizeof(arr)/sizeof(arr[0]);

    int largest_element = largest(arr,size);
    printf("Largest element in the array is :%d ",largest_element);
}