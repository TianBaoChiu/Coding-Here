/*
 * Day 01 - 題目 1A：基本指針操作
 *
 * 目標：理解指針宣告、解參考、透過指針修改變數
 *
 * 編譯方式：gcc ex1a.c -o ex1a && ./ex1a
 */

#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    /* TODO 1: 宣告一個指針 p，讓它指向 a */
    int *p1 = &a;

    /* TODO 2: 透過 p 把 a 的值改成 99（不能直接寫 a = 99） */
    *p1 = 99;
    /* TODO 3: 宣告 int *arr[2]，讓 arr[0] 指向 a，arr[1] 指向 b */
    int *arr[2] = {&a, &b};
    /* TODO 4: 用 for 迴圈印出 arr 每個指針指向的值 */
    for(int i = 0; i < 2 ; i++)
    {
        printf("number of arr[%d] is %d\n", i, *arr[i]);
    }
    /* 預期輸出：
     * a = 99
     * arr[0] = 99
     * arr[1] = 20
     */

    return 0;
}
