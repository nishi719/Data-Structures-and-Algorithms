#include<stdio.h>
#include<string.h>
void compare(char p[20],char q[10]){
 int i,flag =0;
 for(i=0;p[i] != '\0' && q[i] != '\0';i++){
    if(p[i] != q[i])
    flag =1;
    break;
 }
 if(flag==0 && p[i] =='\0' && q[i] =='\0' ){
    printf("\nStrings are  same .");
 }
 else{
    printf("\nStrings are not same .");
 }
}
int main(){
  char a[20] ,b[10];
  printf("\nEnter the 1st string :");
  gets(a);
  printf("\nEnter the 2nd string :");
  gets(b);
  compare(a,b);
}