/*
 * Day 03 - 題目 3A：動態記憶體分配
 *
 * 目標：正確使用 malloc/calloc/realloc/free，避免 memory leak
 *
 * 編譯方式：gcc ex3a.c -o ex3a && ./ex3a
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO 1: 動態分配一個 int 陣列，大小為 n=5
 *         填入 1~5，印出後釋放 */

/* TODO 2: 用 calloc 分配 n=5 個 int
 *         說明 calloc 和 malloc 的差異（寫在註解裡）*/

/* TODO 3: 用 realloc 把陣列從 5 個擴大到 10 個
 *         新增的部分填入 6~10，全部印出後釋放 */

/* TODO 4: 寫一個會 memory leak 的版本（故意的），
 *         然後在旁邊註解說明哪裡 leak、為什麼 */

int main() {
    int n = 5;

    /* TODO 1 */

    /* TODO 2 */

    /* TODO 3 */

    return 0;
}
