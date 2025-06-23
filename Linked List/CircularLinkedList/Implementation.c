#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert at the end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert at the beginning
void insertBegin(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Function to delete a node
void deleteNode(int key) {
    if (head == NULL) return;

    struct Node *curr = head, *prev = NULL;

    // If head is the node to delete
    if (head->data == key) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            struct Node* toDelete = head;
            head = head->next;
            free(toDelete);
        }
        return;
    }

    // For other nodes
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != head);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();

    insertBegin(5);
    display();

    deleteNode(20);
    display();

    return 0;
}
