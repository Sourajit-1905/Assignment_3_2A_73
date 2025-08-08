#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int removeLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    int hasCycle = 0;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = 1;
            break;
        }
    }
    if (!hasCycle) return 0;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
    return 1;
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

void print_list(struct Node* head, int limit) {
    struct Node* current = head;
    int count = 0;
    while (current && count < limit) {
        printf("%d ", current->data);
        current = current->next;
        count++;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int loop_index = 2;
    struct Node* head = build_linked_list_with_loop(arr, n, loop_index);
    removeLoop(head);
    print_list(head, 20);
    return 0;
}