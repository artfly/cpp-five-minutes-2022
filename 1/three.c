// что выведет эта программа?
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * next;
} node_t;

node_t * new_node(int value, node_t * next) {
    node_t * node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        // хз
    }
    node->data = value;
    node->next = next;
    return node;
}

node_t * insert(node_t * head, int value) {
    node_t * cur = head;
    node_t * prev = NULL;
    while (cur != NULL) {
        if (head->data == value) return head;
        if (cur->data > value) break;
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) return new_node(value, head);
    node_t * node = new_node(value, cur);
    prev->next = node;
    return head;
}

int size(node_t * head) {
    int i = 0;
    while (head != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

void clear(node_t * head) {
    while (head != NULL) {
        node_t * next = head->next;
        free(head);
        head = next;
    }
}

int main(int argc, char ** argv) {
    node_t * head = new_node(42, NULL);
    head = insert(head, 13);
    head = insert(head, 42);
    printf("%d\n", size(head));
    return 0;
}
