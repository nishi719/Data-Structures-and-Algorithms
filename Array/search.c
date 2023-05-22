#include<stdio.h>
#include<stdlib.h>
int search(int arr[] ,int n,int x){
    for(int i=0;i<n;i++){
       if(arr[i]==x)
        printf("%d",i);
    
    }
    return -1;
}
int main(){
    int arr[] = {20,5,7,25};
    search(arr,4,25);

}