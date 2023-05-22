#include<stdio.h>
int isSorted(int arr[] ,int size){
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            return 0;
        }
    }
    return 1;
}
int main(){
   int arr1[] ={1,2,3,4,5,6,7};
   int size1 =sizeof(arr1)/sizeof(arr1[0]);

   int arr2[] = {2,6,1,3,5};
   int size2 =sizeof(arr2)/sizeof(arr2[0]);

   if(isSorted(arr1,size1)){
    printf("Array 1 is sorted\n");
   }
   else{
    printf("Array 1 is not sorted\n");
   }

   if(isSorted(arr2,size2)){
    printf("Array 2 is sorted\n");
   }
   else{
    printf("Array 2 is not sorted\n");
   }
}