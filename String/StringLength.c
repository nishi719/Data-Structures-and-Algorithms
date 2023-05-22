#include<stdio.h>
void length(char b[20]){
    int i,l=0;
    for(i=0;b[i] != '\0' ;i++){
        l++;
    }
    printf("\nLength of string : %d" ,l);
}
int main(){
    char a[20];
    printf("\nEnter the string :");
    scanf("%s",a);
    length(a);
}