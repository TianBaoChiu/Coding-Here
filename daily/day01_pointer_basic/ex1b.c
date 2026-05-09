/*
 * Day 01 - 題目 1B：指針運算
 *
 * 目標：理解指針加減法與陣列的關係
 *
 * 編譯方式：gcc ex1b.c -o ex1b && ./ex1b
 */

#include <stdio.h>

int main() {
    int nums[] = {10, 20, 30, 40, 50};
    int *p = nums;

    /* TODO 1: 只用 p 和指針運算（不用 nums[i]），正序印出全部 5 個值 */
    for(int i = 0; i < 5 ; i++)
    {
        printf("num[%d] is %d\n", i, *p);
        p++;
    }
    p--;


    /* TODO 2: 讓 p 指向最後一個元素，然後倒序印出（50, 40, 30, 20, 10） */
    for(int i = 0; i < 5 ; i++)
    {
        printf("num[%d] is %d\n", i, *p);
        p--;
    }

    /* TODO 3: 先猜 (&nums[4] - &nums[0]) 的結果，再印出來驗證 */
    /* 你的猜測：假設整數大小是4個bytes，那答案是16，因為橫跨4個整數大小 */
    printf("diff %d\n", (&nums[4] - &nums[0]));

    /* 預期輸出：
     * 10 20 30 40 50
     * 50 40 30 20 10
     * diff = 4
     */

    return 0;
}
