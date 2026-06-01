//############################################################################
//
//  ex_command_parser_output_atomicity.cpp
//
//############################################################################

// 題目：String / Parser boundary - command parser 與 output atomicity
//
// 實作以下函式：
//
// int parse_command(const char *input, CommandConfig *out_config)
//
// 支援的合法 command 格式固定為：
//
//   "MODE=<digit>;EN=<digit>"
//
// 規則：
// - MODE 只接受 '0'、'1'、'2'、'3'。
// - EN 只接受 '0' 或 '1'。
// - 格式必須完全符合，不接受空白、額外字元、缺欄位或欄位順序交換。
// - 成功時更新 out_config，並回傳 0。
// - invalid input 回傳 -1。
// - 格式錯誤或值超出範圍回傳 -2。
// - 失敗時不得修改 out_config 的任何欄位。
//
// 輸入：
// - input：唯讀 command 字串。
// - out_config：呼叫端提供的 output struct。
//
// 輸出：
// - main() 已提供 success、NULL、格式錯誤、值超範圍與 output atomicity 測試。
//
// 限制：
// - 不可使用 strcpy()、strncpy()、sscanf()、atoi()、strtol() 或 C++ string。
// - 不得修改 input。
// - 必須檢查所有 pointer。
// - 失敗時不可留下半成品 output。
//
// 求職對應 / 面試關聯：
// - C/C++ string parser、boundary check、output parameter、failure atomicity。
// - 對應 firmware / driver 中 UART command parser、factory command、register 設定入口。
//
// 提示 1：
// 先將解析結果放在 local temporary 變數，全部驗證通過後才一次寫入 out_config。
//
// 提示 2：
// 不要只檢查 prefix；最後也要確認 input 已經到 '\0'。
//
// 提示 3：
// invalid input 與格式錯誤要分開：NULL pointer 是 -1，內容不合法是 -2。
//
// 費曼驗證（完成程式後回答 3-5 句）：
// 1. 為什麼 parser 失敗時不應更新 out_config？
// 2. 為什麼不能只 parse 到 EN 後就直接回傳成功？
// 3. 這題如果放在 UART command handler，哪種錯誤最可能造成 firmware bug？

#include <stdio.h>

struct CommandConfig
{
    int mode;
    int enabled;
};

int parse_command(const char *input, CommandConfig *out_config)
{
    // TODO: 在此實作
    (void)input;
    (void)out_config;

    return -1;
}

static void print_result(const char *case_name, int result, const CommandConfig *config)
{
    printf("%s: result=%d, mode=%d, enabled=%d\n",
           case_name,
           result,
           config->mode,
           config->enabled);
}

int main(void)
{
    CommandConfig config = { 9, 9 };
    int result;

    result = parse_command("MODE=2;EN=1", &config);
    print_result("normal", result, &config);
    // 預期: normal: result=0, mode=2, enabled=1

    config = { 7, 7 };
    result = parse_command("MODE=4;EN=1", &config);
    print_result("mode_range", result, &config);
    // 預期: mode_range: result=-2, mode=7, enabled=7

    config = { 6, 6 };
    result = parse_command("MODE=2;EN=9", &config);
    print_result("en_range", result, &config);
    // 預期: en_range: result=-2, mode=6, enabled=6

    config = { 5, 5 };
    result = parse_command("MODE=2;EN=1;", &config);
    print_result("extra_tail", result, &config);
    // 預期: extra_tail: result=-2, mode=5, enabled=5

    config = { 4, 4 };
    result = parse_command("EN=1;MODE=2", &config);
    print_result("wrong_order", result, &config);
    // 預期: wrong_order: result=-2, mode=4, enabled=4

    config = { 3, 3 };
    result = parse_command(NULL, &config);
    print_result("null_input", result, &config);
    // 預期: null_input: result=-1, mode=3, enabled=3

    result = parse_command("MODE=2;EN=1", NULL);
    printf("null_output: result=%d\n", result);
    // 預期: null_output: result=-1

    return 0;
}
