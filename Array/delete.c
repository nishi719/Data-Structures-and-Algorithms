#include<stdio.h>
void delete(int arr[],int size,int index){
    if(index >= size || index<0){
        printf("Invalid index");
        return;
    }
    for(int i=index;i<size-1;i++){
        arr[i] =arr[i+1];
    }
    printf("Element at index %d deleted successfully  \n" ,index);
}
int main(){
    int arr[] ={3,8,12,5,6};
    // int size =sizeof(arr)/sizeof(arr[0]);
    delete(arr,5,1);

    printf("Array after deletion :");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}