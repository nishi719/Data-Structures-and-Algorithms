#include<stdio.h>
void copy(char p[15] ,char q[20]){
    int i;
    for(i=0;p[i] != '\0' ;i++){
        q[i] = p[i];
    }
    q[i] = '\0';
    printf("\nString after copy : %s" , q);

}
int main(){
    char a[15] ,b[20];
    printf("\nEnter a string :");
    scanf("%s", a);
    copy(a,b);
}