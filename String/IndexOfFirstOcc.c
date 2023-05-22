#include<stdio.h>
#include<string.h>
void indexof(char text[20] ,char ch){
    int i,count;
     count=0;   
    for(i=0;text[i]!='\0';i++)
    {
        
        if(text[i]==ch)
            count++;
    }
     
    if(count)
        printf("%c is found %d times in the string %s\n",ch,count,text);
    else
        printf("%c is not found in the string %s\n",ch,text);
 
}
int main()
{
    char text[20];
    
    char ch; 
     
    printf("Enter any string: ");
    gets(text);
     
    printf("Enter character: ");
    scanf("%c",&ch);
    indexof(text,ch);
   
    
}