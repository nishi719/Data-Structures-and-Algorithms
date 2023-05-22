#include<stdio.h>
void delete(char ch[20],int i,int size){
    int j;
    for(j=0;ch[j] != '\0' ; j++){
        if(ch[j]== ch[i]){
            size--;
        }
    }
    printf("%s",ch);
}
int main(){
     char a[20];
     printf("Enter the string :");
     scanf("%s",a);
     int count=0;
     for(int i=0;a[i] != '\0';i++){
        count++;
     }
     delete(a,2,count);
     
}