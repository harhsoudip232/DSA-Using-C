#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};
//global variable
struct node *head = NULL;
struct node *newNode, *temp;

struct node *createLinkedList(){
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
            //head = newNode;
            head=temp=newNode;
        }
        else
        {
            //head->next = newNode;
            temp->next=newNode;
            temp=newNode;
        }

        printf("Do you want to continue? press 0 for end press 1 for continue): ");
        scanf("%d",&ch); //1 = True 0 = false

        if(ch==0){
            break;
        }
    }
    return head;

}

struct node *insertAtBeginning()
{
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the beginning position data: ");
    scanf("%d",&newNode->data);
    newNode->next=head;
    head=newNode;
    return head;
}

struct node *insertAtEnd()
{
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter at the last position data: ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    temp=head;
    if(temp==NULL){
        head=newNode;
    }else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

struct node *insertAtAnyPosition()
{
    int pos,i=1;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    printf("Enter data at specific postion: ");
    scanf("%d",&newNode->data);
    temp=head;
    if(pos==1){
        newNode->next=head;
        head=newNode;
        return head;
    }else{
        while(i<pos-1)//after pos=2 --- exact pos (i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return head;
}

void traverseLinkedList(struct node *head){
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    head = createLinkedList();
    printf("\nThe Elements are: ");
    traverseLinkedList(head);
    /*head=insertAtBeginning();
    traverseLinkedList(head);*/
    /*head=insertAtEnd();
    traverseLinkedList(head);*/
    head=insertAtAnyPosition();
    traverseLinkedList(head);
    return 0;
}