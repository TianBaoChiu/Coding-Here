/*
 * Day 02 - 題目 2C：union 與 struct 的組合（韌體常見用法）
 *
 * 目標：理解 union 的記憶體共用特性，以及暫存器 bitfield 模擬
 *
 * 編譯方式：gcc ex2c.c -o ex2c && ./ex2c
 */

#include <stdio.h>
#include <stdint.h>

/* 模擬一個 8-bit 狀態暫存器：
 *   bit[0]   : power_on
 *   bit[1]   : error
 *   bit[2]   : busy
 *   bit[7:3] : reserved
 */

/* TODO 1: 用 union + struct bitfield 宣告 StatusReg
 *         union 包含一個 uint8_t raw 和一個 struct 的 bitfield */

/* TODO 2: 宣告一個 StatusReg 變數，設定 raw = 0x07，
 *         印出 power_on, error, busy 各是多少 */

/* TODO 3: 只用 raw（不碰 bitfield），用 bit mask 操作：
 *         - 把 error bit 清除
 *         - 把 busy bit 設起來
 *         印出修改後的 raw 值（16進位） */

int main() {
    return 0;
}
