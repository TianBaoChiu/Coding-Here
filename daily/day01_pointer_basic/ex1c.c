/*
 * Day 01 - 題目 1C：指針與函式（傳址呼叫）
 *
 * 目標：理解 pass by pointer vs pass by value 的差異
 *
 * 編譯方式：gcc ex1c.c -o ex1c && ./ex1c
 */

#include <stdio.h>

/* TODO 1: 實作 swap_by_value(int a, int b)
 *         在函式內交換 a, b，觀察 main 裡的值有沒有改變 */
void swap_by_value(int a, int b) {
    /* 填入程式碼 */
    a ^= b;
    b ^= a;
    a ^= b;
}

/* TODO 2: 實作 swap_by_pointer(int *a, int *b)
 *         透過指針真正交換兩個變數的值 */
void swap_by_pointer(int *a, int *b) {
    /* 填入程式碼 */
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    int x = 5, y = 10;

    swap_by_value(x, y);
    printf("After swap_by_value:   x=%d, y=%d\n", x, y);
    /* 預期：x=5, y=10（沒變） */

    swap_by_pointer(&x, &y);
    printf("After swap_by_pointer: x=%d, y=%d\n", x, y);
    /* 預期：x=10, y=5（有變） */

    return 0;
}
