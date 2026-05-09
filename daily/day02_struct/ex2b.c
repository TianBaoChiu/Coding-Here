/*
 * Day 02 - 題目 2B：指針指向 struct
 *
 * 目標：理解 struct 指針、-> 運算子、傳 struct 指針給函式
 *
 * 編譯方式：gcc ex2b.c -o ex2b && ./ex2b
 */

#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t  id;
    uint32_t value;
    uint8_t  status;
} Sensor;

/* TODO 1: 實作 print_sensor(const Sensor *s)
 *         印出 id, value, status */
void print_sensor(const Sensor *s) {
    /* 填入程式碼 */
}

/* TODO 2: 實作 reset_sensor(Sensor *s)
 *         把 value 設為 0，status 設為 0xFF */
void reset_sensor(Sensor *s) {
    /* 填入程式碼 */
}

int main() {
    Sensor s = {.id = 1, .value = 12345, .status = 0x01};

    print_sensor(&s);
    reset_sensor(&s);
    print_sensor(&s);

    /* 預期輸出：
     * id=1, value=12345, status=0x01
     * id=1, value=0, status=0xFF
     */

    return 0;
}
