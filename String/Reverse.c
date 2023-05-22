#include<stdio.h>
void reverse(char rev[20]){
      char temp;
      int i,j,l=0;

      for(i=0;rev[i] !='\0' ;i++){
        l++;

      }
      i=0;
      j=l-1;
      while(i<j){
        temp = rev[i];
        rev[i] = rev[j];
        rev[j] = temp;
        i++;
        j--;
      }
      printf("\nString after reverse : %s",rev);

}
int main(){
    char a[20];
    printf("\nEnter the string :");
    scanf("%s",a);
    reverse(a);
}