//############################################################################
//
//  ex_safe_command_copy.cpp
//
//############################################################################

// 題目：String / Buffer boundary - 安全複製 command buffer
//
// 實作以下函式：
//
// int copy_command(char *dst, int dst_size, const char *src)
//
// - 將 src 複製到 dst。
// - dst 必須永遠以 '\0' 結尾。
// - 若參數無效或 dst_size <= 0，回傳 -1。
// - 若完整複製成功，回傳複製的字元數，不包含 '\0'。
// - 若空間不足而被截斷，仍要正確終止 dst，並回傳 -2。
//
// 輸入：
// - dst：呼叫端提供的可寫入 buffer。
// - dst_size：dst 可用容量，包含結尾 '\0' 的空間。
// - src：唯讀的來源字串。
//
// 輸出：
// - main() 已提供成功、空字串、容量為 1、截斷與無效參數測試。
// - 程式輸出需與預期結果一致。
//
// 限制：
// - 不可使用 strcpy()、strncpy() 或額外的 string library API。
// - 不得修改 src。
// - 必須檢查所有 pointer 與 dst_size。
// - 不可讀寫超出 dst_size 的範圍。
//
// 求職對應 / 面試關聯：
// - C/C++ buffer boundary、const correctness、error handling。
// - 對應 firmware / driver 中 UART command、protocol packet 與外部輸入防護。
//
// 提示 1：
// 先用 guard clause 處理 NULL pointer 與無效容量。
//
// 提示 2：
// 有效可存放的文字數量最多是 dst_size - 1，最後一格留給 '\0'。
//
// 提示 3：
// 複製停止時，需區分「剛好完整複製」與「來源還有字元但空間已滿」。
//
// 費曼驗證（完成程式後回答 3-5 句）：
// 1. 為什麼 firmware / driver 不能直接相信輸入字串長度？
// 2. 為什麼即使被截斷，也必須保證 dst 有 '\0'？
// 3. dst_size == 1 時，函式應做什麼並回傳什麼？

#include <stdio.h>

int copy_command(char *dst, int dst_size, const char *src)
{
	// TODO: 在此實作

	if(dst == nullptr || src == nullptr || dst_size <= 0)
	{
		return -1;
	}

	char * p_dst = dst;
	const char * p_src = src;
	int count = 0;

	for(int i = 0 ; i < dst_size - 1; i++)   
	{
		if(*p_src == '\0')
		{
			break;
		}
		else
		{
			*p_dst = *p_src;
			p_dst++;
			p_src++;
			count++;
		}
	}
	*p_dst = '\0';

	if(*p_src == '\0')
	{
		return count;
	}
	else
	{
		return -2;
	}
}

int main(void)
{
	char	command[8];
	char	tiny[1];
	int		result;

	result = copy_command(command, 8, "START");
	printf("normal: result=%d, command=\"%s\"\n", result, command);
	// 預期: normal: result=5, command="START"

	result = copy_command(command, 8, "");
	printf("empty: result=%d, command=\"%s\"\n", result, command);
	// 預期: empty: result=0, command=""

	result = copy_command(command, 8, "RESET_NOW");
	printf("truncate: result=%d, command=\"%s\"\n", result, command);
	// 預期: truncate: result=-2, command="RESET_N"

	result = copy_command(tiny, 1, "A");
	printf("one_byte: result=%d, command=\"%s\"\n", result, tiny);
	// 預期: one_byte: result=-2, command=""

	result = copy_command(NULL, 8, "START");
	printf("null_dst: result=%d\n", result);
	// 預期: null_dst: result=-1

	result = copy_command(command, 0, "START");
	printf("zero_size: result=%d\n", result);
	// 預期: zero_size: result=-1

	result = copy_command(command, 8, NULL);
	printf("null_src: result=%d\n", result);
	// 預期: null_src: result=-1

	return 0;
}
