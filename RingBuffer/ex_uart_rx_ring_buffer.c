//############################################################################
//
//  ex_uart_rx_ring_buffer.c
//
//############################################################################

// 題目：UART RX Ring Buffer - byte queue 與 command snapshot
//
// 情境：
// UART RX ISR 會一個 byte 一個 byte 收資料，main loop 需要從 buffer 取出 byte，
// 組成完整 command 後再交給 parser。這題先練單 producer / 單 consumer 的
// ring buffer，不先處理 RTOS lock。
//
// 目標：
// 實作以下 API：
//
// int rb_init(RingBuffer *rb, unsigned char *storage, unsigned int capacity)
// int rb_push(RingBuffer *rb, unsigned char byte)
// int rb_pop(RingBuffer *rb, unsigned char *out_byte)
// unsigned int rb_count(const RingBuffer *rb)
// int rb_read_line(RingBuffer *rb, char *out_line, unsigned int out_size)
//
// 規則：
// - rb_init 成功回傳 0；參數無效回傳 -1。
// - rb_push 成功回傳 0；buffer full 回傳 -2；參數無效回傳 -1。
// - rb_pop 成功回傳 0；buffer empty 回傳 -2；參數無效回傳 -1。
// - rb_count 回傳目前 byte 數；參數無效回傳 0。
// - rb_read_line 從 ring buffer 讀到 '\n' 為止，輸出 C string。
// - rb_read_line 成功讀到一行回傳字元數，不包含 '\0'。
// - rb_read_line 若尚未遇到 '\n'，不得消耗 ring buffer 內容，回傳 -2。
// - rb_read_line 若 out_size 不足以容納該行與 '\0'，回傳 -3，且不得留下半成品 output。
// - 所有失敗路徑都要避免污染 output。
//
// 限制：
// - 使用 C 語言寫法，不使用 C++ string / vector。
// - 不使用 malloc。
// - 不使用 strcpy / strncpy / memcpy / memmove。
// - capacity 必須大於 1。
// - 為了區分 full / empty，本題採用 count 欄位，不採用浪費一格空間的作法。
//
// 面試關聯：
// - UART / CLI command handler。
// - ISR producer + main loop consumer 的資料流。
// - buffer full / empty / wrap-around / partial command / output atomicity。
//
// 分段引導：
// 1. 先完成 rb_init / rb_count。
// 2. 再完成 rb_push：寫入 storage[head]，head wrap，count++。
// 3. 再完成 rb_pop：讀出 storage[tail]，tail wrap，count--。
// 4. 最後完成 rb_read_line：先檢查是否存在 '\n'，確認 out_size 足夠後才真正 pop。
//
// 提示：
// - index wrap 可用：
//     next = index + 1;
//     if (next >= capacity) next = 0;
// - rb_read_line 不能一邊找 '\n' 一邊 pop，否則找不到完整行時會破壞資料。
// - 可以先用 local index / local count 掃描 ring buffer，不改 rb。
//
// 費曼驗證（完成程式後回答）：
// 1. Ring buffer 如何分辨 full 和 empty？本題為什麼需要 count？
// 2. rb_read_line 找不到 '\n' 時，為什麼不能先 pop 已讀到的 byte？
// 3. 若 rb_push 在 UART RX ISR 呼叫、rb_pop 在 main loop 呼叫，哪些欄位可能需要 volatile？
// 4. volatile 能不能取代 lock 或 critical section？為什麼？

#include <stdio.h>

#define RB_OK 0
#define RB_INVALID_ARG (-1)
#define RB_EMPTY_OR_FULL (-2)
#define RB_OUTPUT_TOO_SMALL (-3)

typedef struct
{
    unsigned char *storage;
    unsigned int capacity;
    unsigned int head;
    unsigned int tail;
    unsigned int count;
} RingBuffer;

int rb_init(RingBuffer *rb, unsigned char *storage, unsigned int capacity)
{
    // TODO: 在此實作
    (void)rb;
    (void)storage;
    (void)capacity;

    return RB_INVALID_ARG;
}

unsigned int rb_count(const RingBuffer *rb)
{
    // TODO: 在此實作
    (void)rb;

    return 0;
}

int rb_push(RingBuffer *rb, unsigned char byte)
{
    // TODO: 在此實作
    (void)rb;
    (void)byte;

    return RB_INVALID_ARG;
}

int rb_pop(RingBuffer *rb, unsigned char *out_byte)
{
    // TODO: 在此實作
    (void)rb;
    (void)out_byte;

    return RB_INVALID_ARG;
}

int rb_read_line(RingBuffer *rb, char *out_line, unsigned int out_size)
{
    // TODO: 在此實作
    (void)rb;
    (void)out_line;
    (void)out_size;

    return RB_INVALID_ARG;
}

static void push_text(RingBuffer *rb, const char *text)
{
    while (*text != '\0')
    {
        int result = rb_push(rb, (unsigned char)*text);
        printf("push '%c': %d, count=%u\n", *text, result, rb_count(rb));
        text++;
    }
}

int main(void)
{
    unsigned char storage[8];
    RingBuffer rb;
    char line[8] = { 0 };
    unsigned char byte = 0;
    int result;

    result = rb_init(&rb, storage, 8);
    printf("init: %d, count=%u\n", result, rb_count(&rb));
    // 預期: init: 0, count=0

    result = rb_pop(&rb, &byte);
    printf("pop_empty: %d\n", result);
    // 預期: pop_empty: -2

    push_text(&rb, "ABC");

    result = rb_pop(&rb, &byte);
    printf("pop_1: %d, byte=%c, count=%u\n", result, byte, rb_count(&rb));
    // 預期: pop_1: 0, byte=A, count=2

    push_text(&rb, "DEFGHI");
    // 最後一次 push 預期 full: -2，count 維持 8。

    result = rb_read_line(&rb, line, sizeof(line));
    printf("read_no_newline: %d, count=%u\n", result, rb_count(&rb));
    // 預期: read_no_newline: -2, count=8

    while (rb_pop(&rb, &byte) == RB_OK)
    {
        // drain
    }

    push_text(&rb, "OK\nNEXT");

    result = rb_read_line(&rb, line, sizeof(line));
    printf("read_line: %d, line=\"%s\", count=%u\n", result, line, rb_count(&rb));
    // 預期: read_line: 2, line="OK", count=4

    result = rb_read_line(&rb, line, 3);
    printf("read_partial_next: %d, count=%u\n", result, rb_count(&rb));
    // 預期: read_partial_next: -2, count=4

    while (rb_pop(&rb, &byte) == RB_OK)
    {
        // drain
    }

    push_text(&rb, "TOOLONG\n");

    result = rb_read_line(&rb, line, 4);
    printf("read_too_small: %d, count=%u\n", result, rb_count(&rb));
    // 預期: read_too_small: -3, count=8

    return 0;
}
