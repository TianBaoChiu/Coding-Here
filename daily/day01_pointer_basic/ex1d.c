/*
 * Day 01 - 延伸題 1D：雙重指標 (Pointer to Pointer)
 *
 * 目標：理解指向指標的指標，以及如何透過函式改變外部指標的指向
 *
 * 編譯方式：gcc ex1d.c -o ex1d && ./ex1d
 */
#include <stdio.h>

/* TODO 1: 實作 update_pointer 函式，接收一個雙重指標 ptr_to_ptr 和一個整數指標 new_target
 *         將 ptr_to_ptr 指向的內容更改為 new_target */
void update_pointer(int **ptr_to_ptr, int *new_target) {
    /* 填入程式碼 */
}

int main() {
    int a = 100;
    int b = 200;
    int *p = &a;

    printf("Before: *p = %d\n", *p); // 預期輸出 100

    /* TODO 2: 呼叫 update_pointer，傳入 p 的位址與 b 的位址，讓 p 改為指向 b */
    
    printf("After:  *p = %d\n", *p); // 預期輸出 200

    return 0;
}