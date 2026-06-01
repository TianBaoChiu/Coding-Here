//############################################################################
//
//  ex_pointer_review.cpp
//
//############################################################################

// 題目：Pointer 複習 — const array 與 min/max 輸出參數
//
// 實作以下兩個函式：
//
// 1. int count_less_than(const int *arr, int n, int threshold)
//    - 計算陣列中小於 threshold 的元素數量
//    - arr 是唯讀輸入，不可修改陣列內容
//    - 必須使用 pointer 算術，不可使用 arr[i]
//
// 2. int find_min_max(const int *arr, int n, int *out_min, int *out_max)
//    - 找出陣列最小值與最大值
//    - 結果透過 out_min、out_max 回傳
//    - 任一輸入指標為 NULL，或 n <= 0 時，回傳 -1
//    - 成功回傳 0
//
// 輸入：main() 已提供測試資料，不需修改
// 輸出：程式輸出需與預期結果一致
// 限制：
// - 不得引入額外標頭檔
// - 不得把 const int * 強制轉成 int *
// - find_min_max 必須正確處理負數、重複值、單一元素
//
// 提示 1：
// const int *arr 代表你可以讀取 *arr，但不能透過 arr 修改內容。
//
// 提示 2：
// 用 const int *p = arr; 搭配 p < arr + n 走訪陣列。
//
// 提示 3：
// min/max 初始值可先設為第一個元素，再從第二個元素開始比較。

#include <stdio.h>

int count_less_than(const int *arr, int n, int threshold)
{
	// TODO: 在此實作
	const int *p_num = arr;
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(*p_num < threshold)
		{
			count++;
		}
		p_num++;
	}

	return count;
}

int find_min_max(const int *arr, int n, int *out_min, int *out_max)
{
	// TODO: 在此實作
	
	if(arr==NULL || n <= 0 || out_min == NULL || out_max == NULL)
	{
		return -1;
	}

	const int * p_num = arr;

	int min = *p_num ;
	int max = *p_num ;

	for(int i = 0; i < n; i++)
	{
		if(*p_num < min)
		{
			min = *p_num;
		}
		else if(*p_num > max)
		{
			max = *p_num;
		}

		p_num++;
	}
	*out_min = min;
	*out_max = max;


	return 0;
}

int main(void)
{
	const int data[] = { 7, -3, 12, 0, -3, 5 };
	const int single[] = { 42 };
	int       min_value;
	int       max_value;
	int       result;

	printf("less_than_0: %d\n", count_less_than(data, 6, 0));
	// 預期: less_than_0: 2

	result = find_min_max(data, 6, &min_value, &max_value);
	printf("result=%d, min=%d, max=%d\n", result, min_value, max_value);
	// 預期: result=0, min=-3, max=12

	result = find_min_max(single, 1, &min_value, &max_value);
	printf("result=%d, min=%d, max=%d\n", result, min_value, max_value);
	// 預期: result=0, min=42, max=42

	result = find_min_max(NULL, 6, &min_value, &max_value);
	printf("null_arr_result: %d\n", result);
	// 預期: null_arr_result: -1

	result = find_min_max(data, 0, &min_value, &max_value);
	printf("zero_len_result: %d\n", result);
	// 預期: zero_len_result: -1

	return 0;
}
