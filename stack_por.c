#include <stdio.h>
#include <process.h>
#include<stdlib.h>
#define MAX 5

typedef struct
{
    int s[MAX];
    int top;
}stack;
int main()
{
    stack s1;
    int choice, item;
    char ch;

    void create_stack(stack *);
    void push(stack *, int);
    int pop(stack *);
    int peek(stack *);
    int isempty(stack *);
    void display(stack *);
    create_stack(&s1);
    while (1)
    {
        printf("\nChoices: 1.Push\t 2.Pop\t 3.Peek\t 4:Display 5.Exit");
        printf("\nEnter your choice (1-5) ->\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to push = \n");
            scanf("%d", &item);
            push(&s1, item);
            break;
        case 2:
            if (isempty(&s1) == 1)
                printf("underflow : stack Empty");
            else
            {
                item = pop(&s1);
                printf("Element popped =%d\n", item);
            }
            break;
        case 3:
            if (isempty(&s1) == 1)
                printf("underflow : stack Empty");
            else
            {
                item = peek(&s1);
                printf("Element at the top =%d\n", item);
            }
            break;
        case 4:
            display(&s1);
            break;
        case 5:
            exit(0);
        }
    }
}
void create_stack(stack* sp)
{
    sp->top = -1;
}
int isempty(stack* sp)
{
    return (sp->top == -1);
}

void push(stack* sp, int item)
{
    if (sp->top == MAX - 1)
        printf("overflow: stack is full");
    else
    {
        sp->top++;
        sp->s[sp->top] = item;
    }
}

int pop(stack* sp)
{
    int item;
    item = sp->s[sp->top];
    sp->top--;
    return (item);
}

int peek(stack* sp)
{
    int item;
    item = sp->s[sp->top];
    return (item);
}

void display(stack* sp)
{
    int i;
    printf("\nContents of stack =\n");
    for (i = 0; i <= sp->top; i++)
    {
        printf("%d\t", sp->s[i]);
    }
}
