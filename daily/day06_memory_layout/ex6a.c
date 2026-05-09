/*
 * Day 06 - 題目 6A：記憶體區段與 volatile/const
 *
 * 目標：辨別變數落在哪個區段，理解 volatile 的用途
 *
 * 編譯方式：gcc ex6a.c -o ex6a && ./ex6a
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* TODO 1: 在每行宣告旁邊用註解標出它屬於哪個區段：
 *         text / rodata / data / bss / stack / heap */

int    global_init   = 10;        /* 區段：____ */
int    global_uninit;             /* 區段：____ */
const int const_val  = 42;        /* 區段：____ */

void foo() {
    int local = 5;                /* 區段：____ */
    static int s_local = 0;       /* 區段：____ */
    int *p = malloc(sizeof(int)); /* p 在 ____，*p 在 ____ */
    free(p);
}

/* TODO 2: 說明以下 volatile 的使用場景（寫在註解）：
 *         為什麼韌體裡的 memory-mapped register 要宣告成 volatile？ */
volatile uint32_t *UART_STATUS = (volatile uint32_t *)0x40001000;
/* 你的解釋：
 *
 */

/* TODO 3: 以下哪些宣告是合法的？哪些有問題？在旁邊寫說明 */
/*
 * const int *p1;          -- 合法/問題？
 * int * const p2 = &x;   -- 合法/問題？
 * const int * const p3;   -- 合法/問題？
 */

int main() {
    foo();
    return 0;
}
