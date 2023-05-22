#include<stdio.h>
int getsecondlargest(int arr[],int size){
    if(size<2){
        printf("Array should have at least two element ");
        return -1;

    }
    int largest =arr[0];
    int secondlargest = arr[1];

    if(secondlargest>largest){
        int temp;
        temp =largest;
        largest =secondlargest;
        secondlargest =temp;
    }
    for(int i=2;i<size;i++){
        if(arr[i]>largest){
            secondlargest =largest;
            largest =arr[i];
        }
        else if(arr[i]>secondlargest && arr[i]<largest){
            secondlargest =arr[i];
        }
    }
    return secondlargest;
}
int main(){
    int arr[]= {10,5,20,8,15};
    int size = sizeof(arr)/sizeof(arr[0]);

    int second_largest = getsecondlargest(arr,size);
    printf("\nSecond largest element of array : %d ", second_largest);

}