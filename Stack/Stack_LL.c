#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Deleted element is %d",temp->data);
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top element is %d",top->data);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
            case 5:exit(0);
            break;
            default:printf("Invalid choice");
        }
    }
}