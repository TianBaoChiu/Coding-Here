/*
 * Day 07 - 題目 7A：單向鏈結串列
 *
 * 目標：實作基本 linked list — insert / delete / print
 *
 * 編譯方式：gcc ex7a.c -o ex7a && ./ex7a
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    uint32_t    data;
    struct Node *next;
} Node;

/* TODO 1: 實作 node_create(uint32_t data)
 *         動態分配一個 Node，初始化後回傳指針 */
Node *node_create(uint32_t data) {
    return NULL;
}

/* TODO 2: 實作 list_push_front(Node **head, uint32_t data)
 *         在串列最前面插入新節點 */
void list_push_front(Node **head, uint32_t data) {
}

/* TODO 3: 實作 list_push_back(Node **head, uint32_t data)
 *         在串列最後面插入新節點 */
void list_push_back(Node **head, uint32_t data) {
}

/* TODO 4: 實作 list_delete(Node **head, uint32_t data)
 *         刪除第一個值等於 data 的節點，記得 free */
void list_delete(Node **head, uint32_t data) {
}

/* TODO 5: 實作 list_print(Node *head) */
void list_print(Node *head) {
}

/* TODO 6: 實作 list_free(Node **head)
 *         釋放全部節點 */
void list_free(Node **head) {
}

int main() {
    Node *head = NULL;

    list_push_back(&head, 10);
    list_push_back(&head, 20);
    list_push_back(&head, 30);
    list_push_front(&head, 5);
    list_print(head);
    /* 預期：5 -> 10 -> 20 -> 30 -> NULL */

    list_delete(&head, 20);
    list_print(head);
    /* 預期：5 -> 10 -> 30 -> NULL */

    list_free(&head);
    printf("head after free: %s\n", head == NULL ? "NULL" : "NOT NULL");

    return 0;
}
