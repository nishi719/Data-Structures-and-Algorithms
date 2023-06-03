#include<stdio.h>
#include<stdlib.h>
void length(char a[50]){
     int i,l=0;
     for(i=0;a[i] != '\0';i++){
        l++;
     }
    printf("\nLength of string : %d" ,l);
}
void index_of(char a[],char c){
    int i=0;
   for(i=0;a[i]!='\0';i++){
    if(a[i]==c){
       printf("Character %c found at index %d ",c,i);
    }  
   }
   printf("Character %c not found ",c); 
    
}

int get_char(char* ch ,int index){
    int i;
    for(i=0;ch[i] != '\0' && index; i++){
       
    }
    if(ch[i] !=0){
        printf("\nCharacter at index %d : %c" ,index,ch);
    }
    else{
        printf("\nInvalid index");
    }
    
}
void putChar(char* c,int index,char a){
   int i;
    for(i=0;i<index && c[i] != '\0' ;i++ ){
       
    }
   if(c[i] != '\0'){
    c[i] = a;   

   }
   
}
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
void sub_string(char* a, char* substr){
    int i,j,k;

    for(i=0;a[i] !='\0';i++){
        j=0;
        k=i;

        while(substr[j] != '\0' && a[k] == substr[i])
        {
            k++;
            j++;
        }
        if(substr[j] == '\0'){
            printf("\nSubstring found at index %d" ,i);
            }
        else{
            printf("\nSubstring not found");

    }
}
}

void compare(char a[50] ,char b[50]){
     int i,flag=0;
     for(i=0;a[1] != '\0' && b[i] != '\0';i++){
        if(a[i] != b[i])
         flag =1;
         break;
     }
     if(flag ==0 && a[i] == '\0' && b[i] =='\0'){
        printf("\nString are same ");
     }
     else{
        printf("\nString are not same" );
     }
}
void delete(char ch[20],int i,int size){
    int j;
    for(j=0;ch[j] != '\0' ; j++){
        if(ch[j]== ch[i]){
            size--;
        }
    }
    printf("String after deletion : %s",ch);
}
void copy(char p[15] ,char q[20]){
    int i;
    for(i=0;p[i] != '\0' ;i++){
        q[i] = p[i];
    }
    q[i] = '\0';
    printf("\nString after copy : %s" , q);
}

void reverse(char a[50]){
    char temp;
    int i,j,l=0;
    for(i=0;a[i] !='\0';i++){
        l++;
    }
    i=0;
    j=i-1;
    while(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
        }
    printf("\nString after reverse : %s",a);    
}
void lower_to_upper(char a[50]){
    int i;
    for(i=0;a[i] != '\0';i++){
        if(a[i]>='a' && a[i]<='z')
            a[i]=a[i]-32;     
        }
    printf("String in upper case : %s",a);
}
void upper_to_lower(char a[50]){
    for(int i=0;a[i]!='\0';i++){
       if(a[i]>= 'A' && a[i] <='Z')
          a[i] = a[i]+32;
    }
    printf("String in lower case : %s",a);
  }

int main(){

    char a[50],b[50];
    int choice;
    while(1){
        printf("\nString operation: ");
        printf("\n\n1.Length of string: ");
        printf("\n2.Reverse : ");
        printf("\n3.Lower to Uppercase : ");
        printf("\n4.Upper to Lowercase : ");
        printf("\n5.Compare : ");
        printf("\n6.Index of string: ");
        printf("\n7.Putchar: ");
        printf("\n8.getchar: ");
        printf("\n9.Copy : ");
        printf("\n10.Delete : ");
        printf("\n11.Substring : ");
        printf("\n12.Concatenation of two string : ");
        printf("\n13.Exit : ");

        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              printf("\nEnter the string :");
               scanf("%d",a);
              length(a);
              break;

            case 2:
              printf("\nEnter the string :");
              scanf("%d",a);
              reverse(a);
              break;
            case 3:
              printf("\nEnter the string in lower case :");
              scanf("%d",a);
              lower_to_upper(a);
              break;
 
            case 4:
               printf("\nEnter the string in upper case :");
                scanf("%d",a);
               upper_to_lower(a);
               break;

            case 5:
                printf("\nEnter the 1st string :");
                scanf("%d",a);
                printf("\nEnter the 2nd string :");
                 scanf("%d",a);
                compare(a,b);
                break;
            case 6:
               printf("\nEnter the string :");
               scanf("%d",a);
               printf("\nEnter char of string want index :");
               scanf("%d",a);
               index_of(a,b);
               break;

            case 7:
               int c;
                printf("\nEnter the string :");
                scanf("%s",a);
                printf("Enter the position to get char");
                scanf("%d",&c);
                get_char(a,c);
                break;

            case 8:
            int index ;
            char ch;
              printf("\nEnter the string :");
              scanf("%d",a);
              printf("Enter the index want to put char :");
              scanf("%d",&index);
              printf("\Enter the char want to put in string :");
              scanf("%c",ch);
              putChar(a,index,ch);
              break;

            case 9:
               printf("\nEnter a string :");
               scanf("%s", a);
               copy(a,b);
               break;

            case 10:
                printf("Enter the string :");
                scanf("%s",a);
                int count=0;
                for(int i=0;a[i] != '\0';i++){
                count++;
                }
                delete(a,2,count);
            case 11:
            case 12:
                printf("\nEnter the 1st string :");
                scanf("%s",a);
                printf("\nEnter the 2nd string :");
                scanf("%s",b);
                concat(a,b);
                break;
            case 13:
               exit(1);
               break;
           
            default :
                printf("\nWrong choice");
                break;
              
        }
    }
}


