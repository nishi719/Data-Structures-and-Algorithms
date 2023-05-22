#include<stdio.h>
void upperToLower(char low[25]){
   int i;
   for(i=0;low[i] != '\0';i++){
    if(low[i]>= 'A' && low[i] <='Z')
      low[i] = low[i]+32;
   }
   printf("\nString in lower case :%s",low);
}
int main(){
    char a[25];
    printf("\nEnter the string in Upper case :");
    scanf("%s",a);
    upperToLower(a);
}