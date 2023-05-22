#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

int stack[MAX];
char infix[MAX] ,postfix[MAX];
int top = -1;

void push(int);
int pop();
int isEmpty();
void inToPost();
int space(char);
void display();
int precedence(char);
int post_eval();


int main()
{
  int result;
  printf("Enter the infix expression : ");
  gets(infix);

  inToPost();
  result = post_eval();
  display();

  printf("The result obtained after postfix evaluation is : ");
  printf("%d\n" , result);
  
  return 0;
}

void display(){
  int i=0;
  printf("The equivalent postfix expression is :");
  while(postfix[i]){
    printf("%c ", postfix[i++]);
  }
  printf("\n");
}

void inToPost(){
    int i,j=0;
    char symbol,next;

    for(i=0;i<strlen(infix);i++){
       symbol =infix[i];

       if(!space(symbol)){
          switch(symbol){
        case '(':
          push(symbol);
          break;
        case ')':
          while((next =pop()) != '(')
           postfix[j++] = next;
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
              postfix[j++] =pop();
            push(symbol);
            break; 

        default:
          postfix[j++] =symbol;
        
        }
      }
      
    }
  while (!isEmpty())
    postfix[j++] = pop();
  postfix[j] = '\0';
  
}

int space(char c){
  // if symbol is a black space or a tab
  if(c == ' ' || c =='\t')
   return 1;
  else 
   return 0;

}


int precedence(char symbol){
  switch(symbol)
  {
    // Higher value means greater precedence
    case '^':
      return 3;
    case '/':
    case '*':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;     
  }
}

void push(int val){
  if(top == MAX-1){
    printf("\nStack Overflow \n");
    return ;
  }
  top++;
  stack[top] = val;
}

int pop(){
  int val;
  if(top ==-1)
  {
    printf("\nStack Underflow");
    exit(1);
  }
  val = stack[top];
  top = top-1;
  return val;
} 

int isEmpty()
{
   if(top ==-1)
     return 1;
    else
     return 0;
}

int post_eval(){
    int i,a,b;
    for(i=0;i<strlen(postfix) ;i++){
        if(postfix[i] >= '0' && postfix[i] <= '9')
           push(postfix[i] - '0');
        else{
            a = pop();
            b = pop();

            switch(postfix[i]){
                case '+':
                  push(b+a);
                  break;
                case '-':
                  push(b-a);
                  break;
                case '*':
                  push(b*a);
                  break;
                case '/':
                  push(b/a);
                  break;
                case '^':
                  push(pow(b,a));
                  break;
            }
        }
    }
    return pop();
}