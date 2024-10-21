#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = newNode;
}

void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) return;
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 0);
    insertAfter(head->next, 3);

    printf("Linked List: ");
    displayList(head);

    deleteAtBeginning(&head);
    printf("After Deletion at Beginning: ");
    displayList(head);

    deleteAfter(head);
    printf("After Deletion After 1st Node: ");
    displayList(head);

    deleteNode(&head, 2);
    printf("After Deletion of 2: ");
    displayList(head);

    return 0;
}
