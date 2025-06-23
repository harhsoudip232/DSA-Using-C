#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *newNode, *temp;
struct node *createDoublyLinkedList(){
    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next=NULL;
        newNode->prev=NULL;
        if (head == NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            newNode->prev=temp;
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
//forward direction
void traverseLinkedList(struct node *head){
    struct node *ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//backward direction
void reverseTraverseLinkedList(struct node *head){
    struct node *ptr = head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}
int main()
{
    struct node *head;
    head = createDoublyLinkedList();
    printf("Forward direction:\n");
    traverseLinkedList(head);
    printf("Backward direction:\n");
    reverseTraverseLinkedList(head);
    return 0;
}