#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100

int top =-1;

char stack[MAX],infix[50],prefix[50];
void infixToPostfix();
char pop();
void push(int);
int precedence(char );

int main(){
   
    printf("\nEnter infix expression :");
    gets(infix);

    infixToPostfix();
    
    return 0;
}

// method that pushes the elements onto the character stack
void push(int item){
  if(top ==MAX-1)
  {
    printf("\nStack overflow\n");
  }
  else{
    top++;
    stack[top] = infix[item];
  }
}

// method that removes character from stack and returns them
char pop()
{
    char ch;
    if(top < 0){
        printf("\nStack underflow\n");
        exit(0);
    }
    else{
        ch = stack[top];
        stack[top] ='\0';
        top--;
        return (ch);
    }
    return 0;
}

// method that converts String from infix to prefix
// all the strings are assumed to be valid expressions
void infixToPostfix(){
    int i=0,j=0;
    strrev(infix);    // Reverse the infix expression
    while (infix[i] != '\0')
    {
        // if an alphabet is found then copy it to the output string
        if(infix[i] >= 'a' && infix[i] <='z'){
            prefix[j] =infix[i];
            j++;
            i++;
        }
        // In the reversed string, closing bracket will be found first so put it in the stack
        else if(infix[i] == ')' || infix[i] == '}' || infix[i] ==']')
        {
            push(i);
            i++;
        }
        // if an opening bracket is found, then
        else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            if(infix[i] == '(')
            {
                while(stack[top] != ')')
                {
                    prefix[j] =pop();
                    j++;
                }
                pop();
                i++;
            }
            else if(infix[i] == '[')
            {
                while(stack[top] != ']')
                {
                    prefix[j] =pop();
                    j++;

                }
                pop();
                i++;
            }
            else if(infix[i] == '{')
            {
                while(stack[top] != '}')
                {
                    prefix[j] =pop();
                    j++;

                }
                pop();
                i++;
            }
        }
        else{
            // if the stack if empty, then we simply put the operator in stack
            if(top == -1)
            {
                push(i);
                i++;
            }

            // if the precedence of operator is less than the stack top then
            else if(precedence(infix[i]) <precedence(stack[top]))
            {
                prefix[j] =pop();
                j++;
                
                // if you have an operator that has precedence greater than operator
                while(precedence(stack[top]) >precedence(infix[i])){
                    prefix[j] =pop(); 
                    j++;
                    if(top < 0){
                        break;
                    }
                }
                push(i);
                i++;
            }
            // if the precedence of operator is greater than or equal to the stack top 
            else if(precedence(infix[i])>= precedence(stack[top]))
            {
                push(i);
                i++;

            }
        }
    }
    // At the end remove all the operators from the stack
    while(top != -1)
    {
        prefix[j] =pop();
        j++;
    }
    // Reverse the final string before output
    strrev(prefix);
    prefix[j] ='\0';
    printf("\nEquivalent prefix : %s\n" ,prefix);
    
}

/* Function to return precedence of operators */
int precedence(char symbol)
{
    if(symbol == '+' || symbol =='-')
    {
        return (1);
    }
    if(symbol == '*' || symbol == '/')
    {
        return(2);
    }
    if(symbol == '^')
    {
        return(3);
    }
    return 0;
}