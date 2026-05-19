/*
 * 題目：基礎 Pointer 操作三合一
 *
 * 實作以下三個函式：
 *
 * 1. swap(int *a, int *b)
 *    - 透過 pointer 交換兩個整數的值
 *    - 不得使用 std::swap
 *
 * 2. int sum_array(const int *arr, int n)
 *    - 使用 pointer 算術（不可用 arr[i]）計算陣列元素總和
 *    - 回傳總和
 *
 * 3. void find_min_max(const int *arr, int n, int *out_min, int *out_max)
 *    - 找出陣列中的最小值與最大值
 *    - 結果透過 out_min、out_max 指標回傳
 *
 * 輸入：main() 中已提供測試資料，不需修改
 * 輸出：程式輸出需與預期結果一致（見 main 中的 printf）
 * 限制：不得引入額外標頭檔（已提供 stdio.h）
 */

/*
<details><summary>提示 1：swap 怎麼用 pointer？</summary>
要透過 pointer 修改「外部變數」，需要對 pointer 做 dereference（*p）。
交換時需要一個暫存變數。
</details>

<details><summary>提示 2：pointer 算術是什麼？</summary>
`arr` 是指向第 0 個元素的 pointer。
`arr + 1` 指向第 1 個元素，`*(arr + 1)` 等價於 `arr[1]`。
用一個 pointer 從 arr 走到 arr + n，就能遍歷整個陣列。
</details>

<details><summary>提示 3：out 參數怎麼回傳？</summary>
`out_min` 是呼叫者傳進來的 pointer，指向呼叫者的變數。
在函式內 `*out_min = <值>` 就能把結果寫回給呼叫者。
</details>
*/

#include <stdio.h>

void swap(int *a, int *b) {
    // TODO: 在此實作
    int temp_num = *a;
    *a = *b;
    *b = temp_num;
}

int sum_array(const int *arr, int n) {
    // TODO: 在此實作（禁用 arr[i] 語法）

    int sum = 0;
    const int *p = arr;
    for (int i = 0; i < n; i++)
    {
        sum +=*p;
        p++;
    }

    return sum;
}

void find_min_max(const int *arr, int n, int *out_min, int *out_max) {
    // TODO: 在此實作
    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        else if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    *out_min = min;
    *out_max = max;

}

int main(void) {
    // --- 測試 swap ---
    int x = 10, y = 20;
    swap(&x, &y);
    printf("swap: x=%d, y=%d\n", x, y);
    // 預期: x=20, y=10

    // --- 測試 sum_array ---
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("sum: %d\n", sum_array(arr, n));
    // 預期: sum=31

    // --- 測試 find_min_max ---
    int mn, mx;
    find_min_max(arr, n, &mn, &mx);
    printf("min=%d, max=%d\n", mn, mx);
    // 預期: min=1, max=9

    return 0;
}
