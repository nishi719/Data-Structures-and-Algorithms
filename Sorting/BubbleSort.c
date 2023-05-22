#include<stdio.h>

void bubbleSort(int arr[] ,int n){
    for(int i=0;i<n-1;i++){
        int flag =0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp =arr[j];
                arr[j] =arr[j+1];
                arr[j+1] =temp;
                flag=1;
            }
        }
        if(flag==0)
          break;
    }
}
void display(int arr[] ,int n){
    for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int size;
    printf("Enter the size of array :");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the element of array :");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);

    }
    bubbleSort(arr,size);
    printf("\nSorted array :");
    display(arr,size);

}