/*
 * 嵌入式開發題目 1：暫存器位元操作 (Bitwise Operations)
 *
 * 目標：熟悉硬體暫存器常見的 Set, Clear, Toggle, Check 操作。
 * 這是韌體開發中最基礎也最重要的技能。
 */
#include <stdio.h>
#include <stdint.h>

// TODO 1: 實作以下巨集 (Macro) 來操作 bit (提示：使用 <<, |, &, ~, ^)
#define SET_BIT(REG, BIT)     /* 將 REG 的第 BIT 位元設為 1 */
#define CLEAR_BIT(REG, BIT)   /* 將 REG 的第 BIT 位元設為 0 */
#define TOGGLE_BIT(REG, BIT)  /* 將 REG 的第 BIT 位元反轉 */
#define CHECK_BIT(REG, BIT)   /* 檢查 REG 的第 BIT 位元是否為 1 (回傳 0 或非 0) */

int main() {
    uint32_t PORTA = 0x00000000; // 模擬一個 32-bit 硬體暫存器

    // TODO 2: 使用 SET_BIT 將第 3 個位元 (Bit 3) 設為 1
    // 預期 PORTA 變成 0x08
    
    // TODO 3: 使用 SET_BIT 將第 7 個位元 (Bit 7) 設為 1
    // 預期 PORTA 變成 0x88
    
    // TODO 4: 使用 CLEAR_BIT 將第 3 個位元清零
    // 預期 PORTA 變成 0x80

    // TODO 5: 使用 TOGGLE_BIT 反轉第 0 個位元
    // 預期 PORTA 變成 0x81

    // TODO 6: 使用 CHECK_BIT 檢查第 7 個位元和第 3 個位元，並寫 if 判斷印出結果
    // 例如：if (CHECK_BIT(PORTA, 7)) { printf("Bit 7 is SET\n"); }
    
    
    printf("Final PORTA value: 0x%02X\n", PORTA); // 預期輸出 0x81

    return 0;
}