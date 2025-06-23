#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N];
int front=-1;
int rear=-1;
void enqueue(int data)
{ 
    if(rear==N-1){
        printf("stack overflow");
    }else if(front==-1 && rear==-1){
        front=rear=0;
        q[rear]=data;
    }else{
        rear++;
        q[rear]=data;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("stack underflow");
    }else if(front==rear){
        front=rear=-1;
    }else{
        printf("The deleted element is: %d", q[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1){
        printf("stack is empty");
    }else{
        for(i=front;i<rear+1;i++){
            printf("%d ",q[i]);
        }
    }
}

void peek()
{
    if(front==-1 && rear==-1){
        printf("stack is empty");
    }else{
        printf("the first element is: %d", q[front]);
    }
}
int main()
{
    int choice, data;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}