//############################################################################
//
//  ex_vector_push_pop.cpp
//
//############################################################################

// 題目：Vector push / pop 基礎練習 - byte stack
//
// 情境：
// 在做 UART RX Ring Buffer 的 rb_push / rb_pop 前，先用 std::vector 練習
// 「新增一個 byte」、「取出一個 byte」、「檢查 full / empty / invalid arg」。
//
// 重要差異：
// - std::vector::push_back() 是把資料加到尾端。
// - std::vector::pop_back() 是移除尾端資料，而且不會回傳被移除的值。
// - 所以如果要取得被 pop 的 byte，必須先讀 back()，再 pop_back()。
// - 這題是 LIFO stack-like 練習；RingBuffer 的 rb_pop 是 FIFO，下一題再處理。
//
// 實作以下 API：
//
// int vec_push_byte(std::vector<unsigned char> *buffer,
//                   unsigned char byte,
//                   std::size_t max_capacity)
//
// int vec_pop_byte(std::vector<unsigned char> *buffer,
//                  unsigned char *out_byte)
//
// 規則：
// - vec_push_byte 成功回傳 0。
// - vec_push_byte 參數無效回傳 -1。
// - vec_push_byte 若 size 已達 max_capacity，回傳 -2，且不得修改 buffer。
// - vec_pop_byte 成功回傳 0，並透過 out_byte 回傳尾端 byte。
// - vec_pop_byte 參數無效回傳 -1。
// - vec_pop_byte 若 buffer empty，回傳 -2，且不得污染 out_byte。
//
// 限制：
// - 不使用 operator[] 存取最後一個元素；請練習 back()。
// - pop 前必須先確認 buffer 不是 empty。
// - pop_back() 前必須先把 back() 存到 out_byte。
// - 失敗路徑不得修改 output parameter。
//
// 面試關聯：
// - STL container 的基本行為。
// - output parameter 與失敗路徑不污染。
// - 釐清 vector LIFO pop_back 與 ring buffer FIFO pop 的差異。
//
// 提示：
// 1. max_capacity == 0 對這題視為無效參數。
// 2. buffer->size() >= max_capacity 時代表 full。
// 3. pop_back() 的回傳型別是 void，不會把資料吐給你。
//
// 費曼驗證（完成程式後回答）：
// 1. 為什麼 pop_back() 之前要先讀 back()？
// 2. empty 時為什麼不能呼叫 back() 或 pop_back()？
// 3. vector 的 pop_back 跟 ring buffer 的 rb_pop 在資料順序上差在哪裡？
// 4. 為什麼失敗時不要改 out_byte？

#include <cstddef>
#include <cstdio>
#include <vector>

#define VEC_OK 0
#define VEC_INVALID_ARG (-1)
#define VEC_EMPTY_OR_FULL (-2)

int vec_push_byte(std::vector<unsigned char> *buffer,
                  unsigned char byte,
                  std::size_t max_capacity)
{
    //參數無效的情況
    if(buffer == nullptr || max_capacity == 0)
        return VEC_INVALID_ARG;

    //buffer填滿的情況
    if(buffer->size() >= max_capacity)
        return VEC_EMPTY_OR_FULL;

    buffer->push_back(byte);

    return VEC_OK;
}

int vec_pop_byte(std::vector<unsigned char> *buffer,
                 unsigned char *out_byte)
{
    if(buffer == nullptr || out_byte == nullptr)
        return VEC_INVALID_ARG;
    
    if(buffer->size() == 0)
        return VEC_EMPTY_OR_FULL;
    

    *out_byte = buffer->back();

    buffer->pop_back();

    return VEC_OK;
}

static void print_buffer(const char *label,
                         const std::vector<unsigned char> &buffer)
{
    std::printf("%s: size=%zu, data=\"", label, buffer.size());
    for (std::size_t i = 0; i < buffer.size(); ++i)
    {
        std::printf("%c", buffer[i]);
    }
    std::printf("\"\n");
}

int main()
{
    std::vector<unsigned char> buffer;
    unsigned char byte = '?';
    int result = 0;

    print_buffer("init", buffer);
    // 預期: init: size=0, data=""

    result = vec_pop_byte(&buffer, &byte);
    std::printf("pop_empty: result=%d, byte=%c\n", result, byte);
    // 預期: pop_empty: result=-2, byte=?

    result = vec_push_byte(&buffer, 'A', 3);
    std::printf("push_A: result=%d\n", result);
    // 預期: push_A: result=0

    result = vec_push_byte(&buffer, 'B', 3);
    std::printf("push_B: result=%d\n", result);
    // 預期: push_B: result=0

    result = vec_push_byte(&buffer, 'C', 3);
    std::printf("push_C: result=%d\n", result);
    // 預期: push_C: result=0

    print_buffer("after_push", buffer);
    // 預期: after_push: size=3, data="ABC"

    result = vec_push_byte(&buffer, 'D', 3);
    std::printf("push_full: result=%d\n", result);
    print_buffer("after_full", buffer);
    // 預期: push_full: result=-2
    // 預期: after_full: size=3, data="ABC"

    result = vec_pop_byte(&buffer, &byte);
    std::printf("pop_1: result=%d, byte=%c\n", result, byte);
    print_buffer("after_pop_1", buffer);
    // 預期: pop_1: result=0, byte=C
    // 預期: after_pop_1: size=2, data="AB"

    result = vec_pop_byte(&buffer, &byte);
    std::printf("pop_2: result=%d, byte=%c\n", result, byte);
    // 預期: pop_2: result=0, byte=B

    result = vec_pop_byte(&buffer, &byte);
    std::printf("pop_3: result=%d, byte=%c\n", result, byte);
    // 預期: pop_3: result=0, byte=A

    result = vec_pop_byte(&buffer, &byte);
    std::printf("pop_empty_again: result=%d, byte=%c\n", result, byte);
    // 預期: pop_empty_again: result=-2, byte=A

    result = vec_push_byte(nullptr, 'X', 3);
    std::printf("null_buffer_push: result=%d\n", result);
    // 預期: null_buffer_push: result=-1

    result = vec_pop_byte(&buffer, nullptr);
    std::printf("null_out_pop: result=%d\n", result);
    // 預期: null_out_pop: result=-1

    return 0;
}
