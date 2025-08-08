#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

struct Node* trimLeadingZeros(struct Node* head) {
    while (head && head->data == 0) {
        head = head->next;
    }
    return head;
}

int countNodes(struct Node* head) {
    int length = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
    num1 = trimLeadingZeros(num1);
    num2 = trimLeadingZeros(num2);
    int len1 = countNodes(num1);
    int len2 = countNodes(num2);
    if (len1 < len2) return addTwoLists(num2, num1);
    int carry = 0;
    num1 = reverse(num1);
    num2 = reverse(num2);
    struct Node* res = num1;
    while (num2 != NULL || carry != 0) {
        num1->data += carry;
        if (num2 != NULL) {
            num1->data += num2->data;
            num2 = num2->next;
        }
        carry = num1->data / 10;
        num1->data = num1->data % 10;
        if (num1->next == NULL && carry != 0) {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = 0;
            new_node->next = NULL;
            num1->next = new_node;
        }
        num1 = num1->next;
    }
    return reverse(res);
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

void print_list(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr1[] = {0, 1, 2, 3};
    int arr2[] = {9, 9, 9};
    int n1 = 4;
    int n2 = 3;
    struct Node* num1 = build_linked_list(arr1, n1);
    struct Node* num2 = build_linked_list(arr2, n2);
    struct Node* result = addTwoLists(num1, num2);
    print_list(result);
    return 0;
}