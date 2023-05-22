#include<stdio.h>
void lowerToUpper(char up[25]){
     int i;
     for(i=0; up[i] != '\0';i++){
        if(up[i]>='a' && up[i]<='z')
          up[i] = up[i]-32;
     }
     printf("String in upper case :%s" ,up);
}
int main(){
    char a[25];
    printf("\nEnter the string in lower case :");
    scanf("%s",a);
    lowerToUpper(a);
}