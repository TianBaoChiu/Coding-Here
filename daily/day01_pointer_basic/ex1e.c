/*
 * Day 01 - 延伸題 1E：字串與雙指標操作
 *
 * 目標：結合指標加減運算與解參考，實作字串原地反轉
 *
 * 編譯方式：gcc ex1e.c -o ex1e && ./ex1e
 */
#include <stdio.h>

/* TODO 1: 實作 reverse_string 函式
 *         利用兩個指標 (頭、尾) 往中間移動，互相交換字元，直到相遇 */
void reverse_string(char *str) {
    if (str == NULL) return;

    char *start = str;
    char *end = str;

    /* TODO 1-1: 寫一個迴圈，讓 end 指標先移動到字串的最後一個字元 (也就是 '\0' 的前一個) */
    

    /* TODO 1-2: 使用 while 迴圈，當 start < end 時
     *           1. 交換 *start 與 *end 的值
     *           2. start 往後挪 (++)，end 往前挪 (--) */
    
    
}

int main() {
    /* 注意：這裡用 char 陣列宣告而不是 char *text = "..."
     * 因為字串常數區是唯讀的，陣列才能原地修改 */
    char text[] = "Hello Pointer!";

    printf("Original: %s\n", text);

    /* TODO 2: 呼叫 reverse_string 反轉 text */
    
    printf("Reversed: %s\n", text);
    /* 預期輸出: !retnioP olleH */

    return 0;
}