#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int searchKey(int n, struct Node* head, int key) {
    struct Node* temp = head;
    while (temp) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

struct Node* build_linked_list(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    struct Node* current = head;
    for (int i = 1; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = arr[i];
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int key = 3;
    struct Node* head = build_linked_list(arr, n);
    printf("%d\n", searchKey(n, head, key));
    return 0;
}