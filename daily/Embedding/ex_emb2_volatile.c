/*
 * 嵌入式開發題目 2：Volatile 與 記憶體映射暫存器 (Memory-Mapped I/O)
 *
 * 目標：了解如何使用 struct 對應硬體暫存器，並理解 volatile 關鍵字的重要性。
 */
#include <stdio.h>
#include <stdint.h>

// 假設我們有一個 UART 硬體，其暫存器位址偏移如下：
// Offset 0x00: 狀態暫存器 (Status Register) 
// Offset 0x04: 資料暫存器 (Data Register) 

/* TODO 1: 定義一個 UART_RegDef 結構體，包含 status 和 data 兩個 32-bit 成員 */
// 思考：為了防止編譯器優化硬體暫存器的讀寫，成員變數前面應該加上什麼關鍵字？
typedef struct {
    /* 填入程式碼 */
} UART_RegDef;

// 模擬的實體記憶體空間 (僅作測試用，實際開發時指標會直接指向真實物理位址如 0x40000000)
uint8_t simulated_memory[8] = {0}; 

int main() {
    // TODO 2: 宣告一個指標 uart_ptr，型態為 UART_RegDef*，
    // 並將其指向 simulated_memory 的起始位址 (記得強制轉型)
    

    // 模擬硬體改變了狀態 (硬體將狀態暫存器設為 0x01，表示收到資料了)
    simulated_memory[0] = 0x01; 

    // TODO 3: 寫一個 while 迴圈，不斷輪詢 (polling) uart_ptr 的 status，
    // 直到最低位元 (Bit 0) 變成 1 才跳出迴圈
    

    // TODO 4: 從 uart_ptr 的 data 讀取數值並印出
    // (我們先假裝硬體在 data 暫存器放了收到的字元 'A'，ASCII 碼為 0x41)
    simulated_memory[4] = 0x41; 
    
    // 印出透過 uart_ptr->data 讀到的值

    return 0;
}