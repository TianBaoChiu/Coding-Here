/*
 * Day 05 - 題目 5A：Bit 操作基礎（韌體最常用）
 *
 * 目標：掌握 set/clear/toggle/check bit，這是嵌入式面試必考
 *
 * 編譯方式：gcc ex5a.c -o ex5a && ./ex5a
 */

#include <stdio.h>
#include <stdint.h>

/* TODO 1: 實作以下四個 macro（用 #define）：
 *   BIT_SET(reg, bit)    - 設定第 bit 位
 *   BIT_CLEAR(reg, bit)  - 清除第 bit 位
 *   BIT_TOGGLE(reg, bit) - 翻轉第 bit 位
 *   BIT_CHECK(reg, bit)  - 檢查第 bit 位是否為 1（回傳非零即為真）
 */

/* TODO 2: 模擬一個 GPIO 控制暫存器 uint8_t gpio_reg = 0x00
 *   - 設定 bit2（LED on）
 *   - 設定 bit5（UART TX enable）
 *   - 檢查 bit2 是否為 1
 *   - 清除 bit2（LED off）
 *   - 翻轉 bit5
 *   每步操作後印出 gpio_reg 的十六進位值 */

/* TODO 3: 實作 count_set_bits(uint8_t val)
 *         計算一個 byte 裡有幾個 bit 是 1
 *         （不可用 __builtin_popcount） */
int count_set_bits(uint8_t val) {
    /* 填入程式碼 */
    return 0;
}

int main() {
    return 0;
}
