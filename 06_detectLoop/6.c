#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

struct Node* build_linked_list_with_loop(int arr[], int n, int loop_index) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    nodes[0] = head;
    struct Node* current = head;
    for (int i = 1; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = arr[i];
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
        nodes[i] = new_node;
    }
    if (loop_index != -1) {
        current->next = nodes[loop_index];
    }
    free(nodes);
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int loop_index = 2;
    struct Node* head = build_linked_list_with_loop(arr, n, loop_index);
    printf("%d\n", detectLoop(head));
    return 0;
}