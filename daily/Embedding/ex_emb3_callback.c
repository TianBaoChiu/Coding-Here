/*
 * 嵌入式開發題目 3：函式指標與中斷回呼 (Callbacks)
 *
 * 目標：了解如何註冊函式指標，模擬硬體中斷發生時呼叫對應的處理常式 (ISR)。
 */
#include <stdio.h>

// 定義一個函式指標型態 isr_callback_t，不接收參數且不回傳值 (void)
typedef void (*isr_callback_t)(void);

// 假設我們系統最多支援 3 個硬體中斷 (IRQ 0 ~ 2)
isr_callback_t isr_table[3] = {NULL, NULL, NULL};

/* TODO 1: 實作註冊中斷函式 */
// 接收一個中斷編號 irq_num 和一個函式指標 callback
// 將 callback 存入 isr_table 對應的位置 (請先檢查 irq_num 是否在 0~2 之間)
void register_isr(int irq_num, isr_callback_t callback) {
    /* 填入程式碼 */
}

/* TODO 2: 模擬硬體觸發中斷 */
// 接收中斷編號 irq_num，如果 isr_table 中有註冊該函式 (不為 NULL)，就呼叫它
void hardware_trigger_irq(int irq_num) {
    /* 填入程式碼 */
}

// --- 以下為使用者自定義的中斷處理常式 (ISR) ---

void my_timer_isr(void) {
    printf("[ISR] Timer Interrupt Triggered!\n");
}

void my_gpio_isr(void) {
    printf("[ISR] Button Pressed (GPIO Interrupt)!\n");
}

int main() {
    /* TODO 3: 將 my_timer_isr 註冊到 IRQ 0 */
    

    /* TODO 4: 將 my_gpio_isr 註冊到 IRQ 2 */
    

    // 模擬硬體隨機觸發中斷
    printf("Simulating hardware interrupts...\n");
    hardware_trigger_irq(0); // 預期輸出 Timer 訊息
    hardware_trigger_irq(1); // 沒有註冊，不該有動作，也不該發生 Crash
    hardware_trigger_irq(2); // 預期輸出 GPIO 訊息

    return 0;
}