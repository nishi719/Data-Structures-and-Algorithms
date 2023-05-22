#include<stdio.h>
void insertionSort(int arr[] ,int n){
        for(int i=1;i<n;i++)
        {
           int temp =arr[i];
           int j =i-1;

           while(j>=0 && arr[j]>temp)
           {
            arr[j+1]=arr[j];
            j--;
           }
           arr[j+1]=temp;
        }
}
void display(int arr[] ,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int size;
    printf("Enter the size of array :");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the element of array :");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,size);
    printf("Sorted array :");
    display(arr,size);


}