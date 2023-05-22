#include<stdio.h>
void concat( char p[25] ,char q[15]){
    int i, l=0;
    for(i=0;p[i] != '\0';i++){
        l++;
    }
    for(i=0; q[i] != '\0' ; i++){
       p[l+i] = q[i];
    }
    p[l+i] = '\0';
    printf("\nString after concat : %s" , p);

}
int main(){
    char a[25],b[15];
    printf("\nEnter the 1st string :");
    scanf("%s",a);
    printf("\nEnter the 2nd string :");
    scanf("%s",b);
    concat(a,b);
}