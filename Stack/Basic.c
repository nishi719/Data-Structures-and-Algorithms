#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack
{
    int items[MAX_SIZE];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isEmpty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(st *s)
{
    if (s->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void push(st *s, int newitem)
{
    if (isFull(s))
    {
        printf("STACK FULL\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("Item popped= %d\n", s->items[s->top]);
        s->top--;
    }
}

void display(st *s)
{
    if (isEmpty(s))
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = s->top; i >= 0; i--)
            printf("%d\n", s->items[i]);
    }
}

int main()
{
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    display(s);

    pop(s);
    pop(s);

    display(s);

    return 0;
}