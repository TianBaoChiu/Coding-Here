/*
 * 題目：Pointer 進階 — 字串處理
 *
 * 實作以下兩個函式：
 *
 * 1. int str_len(const char *s)
 *    - 計算字串長度，不得呼叫 strlen()
 *    - 必須使用 pointer 算術（不可用 s[i]）
 *
 * 2. void str_rev(char *s)
 *    - 就地反轉字串（in-place），不得使用額外陣列
 *    - 必須使用 pointer 算術（不可用 s[i]）
 *
 * 輸入：main() 中已提供測試資料，不需修改
 * 輸出：程式輸出需與預期結果一致（見 main 中的 printf）
 * 限制：不得引入額外標頭檔（stdio.h 已提供；string.h 僅限 main 內部使用）
 */

/*
<details><summary>提示 1：str_len 怎麼走到字串結尾？</summary>
C 字串以 '\0' 結尾。
用一個 pointer 從 s 開始往後移，直到 *p == '\0' 為止。
走了幾步，長度就是幾。
</details>

<details><summary>提示 2：str_rev 要怎麼「就地」反轉？</summary>
準備兩個 pointer：一個指向字串開頭，一個指向結尾（最後一個非 '\0' 的字元）。
兩者同時往中間靠攏，每次交換兩個 pointer 所指的字元。
當兩個 pointer 相遇或交叉，就結束。
</details>

<details><summary>提示 3：結尾 pointer 怎麼定位？</summary>
先用 str_len（或同樣的走法）找到長度 n。
結尾 pointer = s + n - 1，指向最後一個有效字元。
</details>
*/

#include <stdio.h>

int str_len(const char *s)
{
    // TODO: 在此實作
}

void str_rev(char *s)
{
    // TODO: 在此實作
}

int main(void)
{
    // --- 測試 str_len ---
    const char *msg = "hello";
    printf("len: %d\n", str_len(msg));
    // 預期: len: 5

    // --- 測試 str_rev ---
    char buf[] = "abcde";
    str_rev(buf);
    printf("rev: %s\n", buf);
    // 預期: rev: edcba

    char buf2[] = "abcd";
    str_rev(buf2);
    printf("rev: %s\n", buf2);
    // 預期: rev: dcba

    return 0;
}
