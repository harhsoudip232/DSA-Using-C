#include <stdio.h>
#include <stdlib.h>
// define the node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
//global variable
struct node *head = NULL;
struct node *newNode, *temp, *tail;
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
// delte form beginning
void deleteFormBeg()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;  // Update tail when the list becomes empty
        }
        free(temp);
    }
}
// delete form last node
void deleteLastNode()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
        free(temp);
    }
}
//length of linked list
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
//delte at any position
void deleteAtAnyPos()
{
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > length())
    {
        printf("Invalid position! Please enter position between 1 to %d\n", length());
    }
    else if (pos == 1)
    {
        deleteFormBeg();
    }
    else if (pos == length())
    {
        deleteLastNode();
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
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
    head = createDoublyLinkedList();
    printf("Forward direction:\n");
    traverseLinkedList(head);
    deleteFormBeg();
    printf("After deleting the beginning node:\n");
    traverseLinkedList(head);
    deleteLastNode();
    printf("After deleting the last node:\n");
    traverseLinkedList(head);
    printf("After deleting at any pos node:\n");
    deleteAtAnyPos();
    traverseLinkedList(head);
    return 0;
}