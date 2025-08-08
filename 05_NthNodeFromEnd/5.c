#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getKthFromLast(struct Node* head, int k) {
    struct Node* main = head;
    struct Node* ref = head;
    for (int i = 1; i < k; i++) {
        ref = ref->next;
        if (!ref) return -1;
    }
    while (ref->next) {
        ref = ref->next;
        main = main->next;
    }
    return main->data;
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
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int k = 2;
    struct Node* head = build_linked_list(arr, n);
    printf("%d\n", getKthFromLast(head, k));
    return 0;
}