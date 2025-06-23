// array implementation
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX]; // stack[5]
int top = -1;
// push
void push()
{
    int item;
    printf("Enter the item: ");
    scanf("%d", &item);
    if (top == MAX - 1) //-1==4
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("The element is now inserted");
        top = top + 1;
        stack[top] = item;
    }
}

// display
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The elements in the stack are: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d", stack[i]);
            printf("\n");
        }
    }
}
// pop
void pop()
{
    int data;
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        data = stack[top];
        top--; //top=top-1
        printf("The deleted element is: %d", data);
    }
}
// peek
// print the top most element
void peek()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("%d", stack[top]);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid chocie........");
        }
    }
    return 0;
}