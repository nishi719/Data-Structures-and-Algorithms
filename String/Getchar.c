#include<stdio.h>
int getch(char ch[20] ,int p){
    int i;
    for(i=0;ch[i] != '\0'; i++){
        if(i==p)
        return ch[i-1];   
    }
    
}
int main(){
    char a[20];
    int b;
    printf("\nEnter the string :");
    scanf("%s",a);
    printf("Enter the position to get char");
    scanf("%d",&b);
    getch(a,b);
    printf("%s",a[b-1]);
    
}