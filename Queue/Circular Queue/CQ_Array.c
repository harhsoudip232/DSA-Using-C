#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if(front==-1 && rear==-1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    //queue is full
    else if(((rear+1)%MAX) == front)
    {
        printf("Queue is full\n");
    }
    //queue is full but somee space remain
    else{
        rear=(rear+1)%MAX;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
    }
        
}

void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("\nQueue is: ");
        while(i != rear)
        {
            printf("%d ", queue[i]);
            i = (i+1)%MAX;
        }
        printf("%d ", queue[rear]);
    }
    printf("\n");
}

//using switch
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
