#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
};

struct node *createLinkedList(){
    struct node *head = NULL;
    struct node *newNode, *temp;
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
    /*struct node *head, *newNode, *temp, *ptr;
    head = NULL;
    int ch;
    while (ch)
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

        printf("Do you want to continue then hit (0 or 1)");
        scanf("%d",&ch); //1 = True 0 = false
    }*/

    struct node *head;
    head = createLinkedList();
    printf("\nThe Elements are: ");
    traverseLinkedList(head);

    // print the data -- traversal 
    /*ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }*/
    return 0;
}