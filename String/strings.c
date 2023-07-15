#include<stdio.h>
#include<stdlib.h>
int length(char a[]){
     int i,l=0;
     for(i=0;a[i] != '\0';i++){
        l++;
     }
    return l;
}
int index_of(char a[],char c){
   for(int i=0; i<length(a); i++)
    {
        if(a[i]==c)
            return i;
    }

    return -1;
    
}

char get_char(char ch[] ,int index){
     if(index>=length(ch))
        return '\0';

    return ch[index];
    
}
void putChar(char* c,int index,char a){
   for(int j=length(c)-1; j>=index; j--)
        c[j+1] = c[j];
    c[index] = a;
   
}
void concat( char* p ,char* q){
   int i;
    int j = length(p);
    for(i=0; q[i]!='\0'; i++)
        p[i+j] = q[i];
    p[i+j] = '\0';

}
void substring(char a[], int i, int size, char* s)
{
    int k=0;
    for(int j=i; j<size; j++)
    {
        s[k] = a[j];
        k++;
    }
}

int compare(char* a, char* b)
{
    int flag = 0;
    while(*a!='\0' || *b!='\0')
    {
        if(*a==*b)
        {
            a++;
            b++;
        }
        else if((*a=='\0' || *b!='\0') || *a!=*b)
        {
            flag = 1; 
            return -1;
        }
        else if((*b=='\0' || *a!='\0') || *a!=*b)
        {
            flag = 1; 
            return 1;
        }
    }
    if (flag==0)
    {
        return 0;
    }
}
void delete(char* a, int i, int size)
{
    for(int j=size; j<length(a);j++)
    {
        a[i] = a[j];
        i++;
    }
    for(int k=i; k<length(a); k++)
        a[k] = '\0';
}


void copy(char* a, char* b)
{
    for(int i=0; i<length(a); i++)
        b[i] = a[i];
}

void reverse(char a[]){
    char temp;
    int i,j,l=0;
    for(i=0;a[i] !='\0';i++){
        l++;
    }
    i=0;
    j=i-1;
    for(i=0,j=l-1;i<j ;i++,j--) {
        temp =a[i];
        a[i] =a[j];
        a[j]=temp;
    } 
    
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

    // char a[50],b[50];
    // int choice;
    // int index ;
    // char ch;
    // while(1){
    //     printf("\nString operation: ");
    //     printf("\n\n1.Length of string: ");
    //     printf("\n2.Reverse : ");
    //     printf("\n3.Lower to Uppercase : ");
    //     printf("\n4.Upper to Lowercase : ");
    //     printf("\n5.Compare : ");
    //     printf("\n6.Index of string: ");
    //     printf("\n7.Putchar: ");
    //     printf("\n8.getchar: ");
    //     printf("\n9.Copy : ");
    //     printf("\n10.Delete : ");
    //     printf("\n11.Substring : ");
    //     printf("\n12.Concatenation of two string : ");
    //     printf("\n13.Exit : ");

    //     printf("\nEnter your choice :");
    //     scanf("%d",&choice);
    //     switch(choice){
    //         case 1:
    //           printf("\nEnter the string :");
    //            scanf("%s",a);
    //           length(a);
    //           break;

    //         case 2:
    //           printf("\nEnter the string :");
    //           scanf("%s",a);
    //           reverse(a);
    //           printf("\nString after reverse : %s" , a);
              
    //           break;
    //         case 3:
    //           printf("\nEnter the string in lower case :");
    //           scanf("%s",a);
    //           lower_to_upper(a);
    //           break;
 
    //         case 4:
    //            printf("\nEnter the string in upper case :");
    //             scanf("%s",a);
    //            upper_to_lower(a);
    //            break;

    //         case 5:
    //             printf("\nEnter the 1st string :");
    //             scanf("%s",a);
    //             printf("\nEnter the 2nd string :");
    //              scanf("%d",a);
    //             compare(a,b);
    //             break;
    //         case 6:
    //            printf("\nEnter the string :");
    //            scanf("%s",a);
    //            printf("\nEnter char of string want index :");
    //            scanf("%s",b);
    //            index_of(a,b);
    //            break;

    //         case 7:
              
    //             printf("\nEnter the string :");
    //             scanf("%s",a);
    //             printf("Enter the position to get char");
    //             scanf("%d",&index);
    //             get_char(a,index);
    //             break;

    //         case 8:
            
    //           printf("\nEnter the string :");
    //           scanf("%s",a);
    //           printf("Enter the index want to put char :");
    //           scanf("%d",&index);
    //           printf("\Enter the char want to put in string :");
    //           scanf("%s",ch);
    //           putChar(a,index,ch);
    //           break;

    //         case 9:
    //            printf("\nEnter a string :");
    //            scanf("%s", a);
    //            copy(a,b);
    //            break;

    //         case 10:
    //             printf("Enter the string :");
    //             scanf("%s",a);
    
    //             delete(a,0,2);
    //         case 11:
    //             printf("\Enter the string :");
    //             scanf("%s",a);
    //             printf("\nEnter the substring :");
    //             scanf("%s",b);
    //             substring(a,1,3,b);
    //             break;
    //         case 12:
    //             printf("\nEnter the 1st string :");
    //             scanf("%s",a);
    //             printf("\nEnter the 2nd string :");
    //             scanf("%s",b);
    //             concat(a,b);
    //             break;
    //         case 13:
    //            exit(1);
    //            break;
           
    //         default :
    //             printf("\nWrong choice");
    //             break;
              
    //     }
    // }

    char str[50] = "NISHI";
    char s[] = "KUMARI";
    char result[100];

    printf("\nlength of string = %d\n", length(str));
    printf("\nIndex of B = %d\n", index_of(str, 'B'));
    printf("\nChar at 2 index in str = %c\n", get_char(str, 2));
    putChar(str, 4, '@');
    printf("%s\n", str);
    printf("\nString after concatenation :");
    concat(str, s);
    printf("%s\n",str);
    printf("\nString after coping :");
    copy(str, result);
    printf("%s\n",result);
    printf("\nString after deletion :");
    delete(str, 0, 2);
    printf("%s\n",str);
    printf("\nAfter compare :");
    printf("%d\n", compare(str, result));
    printf("\nString in upper case :");
    lower_to_upper(str);
    printf("%s\n", str);
    printf("\nString in lower case :");
    upper_to_lower(str);
    printf("%s\n", str);
    printf("\nSubstring :");
    substring(str, 1, 3, result);
    printf("%s\n", result);
    printf("\nString after reversing :");
    reverse(s);
    printf("%s\n", s);

    return 0;
}


