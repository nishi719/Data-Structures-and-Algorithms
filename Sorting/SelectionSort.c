#include<stdio.h>


void swap(int *a,int *b){
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_term =i;
        for(int j=i+1 ;j<n;j++){
          if(arr[j]<arr[min_term])
             min_term =j;  
        }
        
        swap(&arr[min_term],&arr[i]);
    }
}
void display(int arr[] ,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
  int n;
  printf("Enter the size of array :");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the element of array :");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

  }
  selectionSort(arr ,n);
  printf("\nSorted array :");
  display(arr,n);

  
}