#include <stdio.h>
int strlen(char c[]){
    int i=0;
    while(c[i]!='\0'){
        i++;
    }
    return i;



}
int indexof(char a[],char c){
    int i=0;
    while(a[i]!='\0'){
        if(a[i]==c){
            return i;
        }
        i++;
    }
}



char getChar(char c[],int index){
    return c[index];

}
void putChar(char c[],char a,int index){
    for(int i=strlen(c)-1;i>index;i--){
        c[i+1]=c[i];

    }
    c[index]=a;

}
char* concat(char a[],char b[]){
    int l=strlen(a)+strlen(b);
    char c[l];
    int i=0;
    while(a[i]!='\0'){
        c[i]=a[i];
        i++;
    }
    int j=0;
    while(b[j]!='\0'){
        c[i]=b[j];
        i++;
        j++;
    }
    return c;


}
char* substring(char a[], int x, int size){
    int i=0;
    char d[strlen(a)];
    while(a[i]!='\0'){
        if(a[i]==x){
            int s=0;
            while(s!=size){
                d[s]=a[i];
                s++;
            }

        }
        i++;
    }
return d;
}
int compare(char a[],char b[]){
    int i=0;
    while(a[i]!=b[i]){
        if(a[i]=='\0'||b[i]>a[i]){
            return -1;
        }
        else if(b[i]=='\0'||b[i]<a[i]){
            return 1;
        }
        else{
            return 0;
        }
        i++;

    }




}
void deleteChar(char a[],int x, int size){

    for(int i=x;i<x+size;i++){
        while(a[i]!='0'){


        a[i]=a[i+size];
        }
    }


}
void copy(char a[],char b[]){
    int i=0;
    int l=strlen(a);
    while(b[i]!='\0'){
        a[l]=b[i];
        i++;
        l++;
    }


}

void reverse(char a[]){
    for(int i=strlen(a)-1;i>=0;i--){
        printf(a[i]+" ");
    }


}
void uppercase(char a[]){
    for(int i=0;i<strlen(a);i++){
        if(a[i]>96){
        a[i]=a[i]-32;

    }

    }
    for(int i=0;i<strlen(a);i++){
        printf("%c ",a[i]);
    }

}
void lowercase(char a[]){
    for(int i=0;i<strlen(a);i++){
        if(a[i]<96){
        a[i]=a[i]+32;


    }

    }
    for(int i=0;i<strlen(a);i++){
        printf("%c ",a[i]);
    }

}


int main(){

    char a[100]="akshitasingh";
    char b[100]="compare";
    printf("%d\n",compare(a,b));
    uppercase(a);
    printf("\n");
    lowercase(a);
    printf("\n");



}


