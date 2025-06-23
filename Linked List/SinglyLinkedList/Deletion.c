#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};
// global variable
struct node *head = NULL;
struct node *newNode, *temp;

struct node *createLinkedList()
{
    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = 0;
        // head=newNode;
        if (head == NULL)
        {
            // head = newNode;
            head = temp = newNode;
        }
        else
        {
            // head->next = newNode;
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to continue? press 0 for end press 1 for continue): ");
        scanf("%d", &ch); // 1 = True 0 = false

        if (ch == 0)
        {
            break;
        }
    }
    return head;
}

struct node *deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node *deleteAtEnd(){
    struct node *prev;
    if(head==NULL){
        printf("List is empty");
    }else{
        temp=head;
        //move temp pointer
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==head){
            head=NULL;
        }else{
            prev->next=NULL;
        }
        free(temp);
    }
    return head;
}

struct node *deleteAtGivenPos()
{
    struct node *nextNode;
    int pos,i=1;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    nextNode=temp->next;
    temp->next=nextNode->next;
    free(nextNode);
    return head;
}
void traverseLinkedList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    // struct node *head;
    createLinkedList();
    traverseLinkedList(head);
    printf("\n");
    head=deleteAtBeginning();
    traverseLinkedList(head);
    printf("\n");
    head=deleteAtEnd();
    traverseLinkedList(head);
    printf("\n");
    head=deleteAtGivenPos();
    traverseLinkedList(head);
    return 0;
}