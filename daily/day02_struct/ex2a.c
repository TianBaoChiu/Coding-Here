/*
 * Day 02 - 題目 2A：結構體基礎與 padding
 *
 * 目標：理解 struct 宣告、成員存取、記憶體對齊（alignment）
 *
 * 編譯方式：gcc ex2a.c -o ex2a && ./ex2a
 */

#include <stdio.h>
#include <stddef.h>  /* offsetof */

/* TODO 1: 宣告一個 struct Sensor，包含：
 *   - uint8_t  id
 *   - uint32_t value
 *   - uint8_t  status
 * 先猜 sizeof(struct Sensor) 是多少，再印出來驗證 */

/* TODO 2: 宣告同樣欄位但重新排列順序，讓 sizeof 最小
 *         命名為 struct SensorPacked */

/* TODO 3: 印出每個欄位的 offsetof，觀察 padding 的位置 */

int main() {
    /* 你的猜測 sizeof(struct Sensor) = ____ */
    /* 你的猜測 sizeof(struct SensorPacked) = ____ */

    return 0;
}
