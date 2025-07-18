#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Deleted element is %d",temp->data);
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
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

void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Front element is %d",front->data);
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice");
        }
    }
}