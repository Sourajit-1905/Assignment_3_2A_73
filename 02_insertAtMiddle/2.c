#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node* insertInMiddle(struct Node* head, int x) {
    struct Node* newnode = createNode(x);

    if (head == NULL)
        return newnode;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast == NULL)
            break;
        slow = slow->next;
    }

    newnode->next = slow->next;
    slow->next = newnode;

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* createLinkedList(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = createLinkedList(arr, n);

    printf("Original Linked List:\n");
    printList(head);

    int x = 99;
    head = insertInMiddle(head, x);

    printf("\nLinked List After Insertion:\n");
    printList(head);

    return 0;
}