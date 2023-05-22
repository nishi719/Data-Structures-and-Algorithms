#include<stdio.h>
int insert(int arr[],int size,int x,int pos,int cap){
    if(size==cap)
    return size;
    int index = pos-1;
    for(int i=size-1;i>=index;i--)
       arr[i+1]==arr[i];
    arr[index]=x;

    return (size+1);  

}
int main(){
    int arr[]= { 5,10,20,4};
    int x,pos;
    printf("Enter the element to be inserted :");
    scanf("%d",&x);
    printf("Enter the position at which want to be inserted :");
    scanf("%d",&pos);
    
    insert(arr,4,x,pos,10);

    printf("Array element are :");
    for(int i=0;i<4;i++){
        printf("%d  ",arr[i]);
    }

}