/*
 * Day 04 - 題目 4A：Function Pointer
 *
 * 目標：宣告、賦值、呼叫 function pointer；callback 模式
 *
 * 編譯方式：gcc ex4a.c -o ex4a && ./ex4a
 */

#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

/* TODO 1: 宣告一個 function pointer 型別 op_func_t
 *         代表「接受兩個 int，回傳 int」的函式 */

/* TODO 2: 實作 calculate(int a, int b, op_func_t op)
 *         呼叫 op(a, b) 並回傳結果 */

/* TODO 3: 在 main 裡建立一個 op_func_t 陣列，
 *         存入 add, sub, mul，用迴圈對 (10, 3) 全部呼叫一遍 */

/* TODO 4: 實作一個簡單的 dispatcher：
 *         根據字元 '+' '-' '*' 回傳對應的 function pointer */
/* op_func_t get_op(char c) { ... } */

int main() {
    /* 預期輸出：
     * add(10,3) = 13
     * sub(10,3) = 7
     * mul(10,3) = 30
     */
    return 0;
}
