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
struct node *newNode, *tail, *temp;
struct node *createDoublyLinkedList()
{
    int ch;
    while (1)
    {
        newNode = (struct node *)malloc(sizeof(struct node)); // dynamic mempory allocate
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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
struct node *insertAtBeg()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    // LOGIC
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return head;
}
struct node *insertAtEnd()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    // LOGIC
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return head;

    return head;
}
int length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
struct node *insertAtAnyPos()
{
    int pos, i = 1, count;
    printf("Enter the position: ");
    scanf("%d", &pos);
    // warning
    if (pos <= 0 || pos > (count = length()))
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        printf("beginning insertion done\n");
        insertAtBeg();
    }
    else
    {
        // at any position code
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        temp=head;
        while(i<(pos-1))
        {
            temp=temp->next;
            i++;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->next->prev=newNode;
    }

    return head;
}
// forward direction
void traverseLinkedList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *head;
    head = createDoublyLinkedList();
    printf("Forward direction:\n");
    traverseLinkedList(head);
    printf("Insertion at the beginning: \n");
    head = insertAtBeg();
    traverseLinkedList(head);
    printf("Insertion at the End: \n");
    head = insertAtEnd();
    traverseLinkedList(head);
    printf("Insertion at any position: \n");
    head = insertAtAnyPos();
    traverseLinkedList(head);

    return 0;
}