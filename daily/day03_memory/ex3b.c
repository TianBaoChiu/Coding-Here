/*
 * Day 03 - 題目 3B：動態分配 struct 陣列
 *
 * 目標：malloc struct、透過指針操作、正確 free
 *
 * 編譯方式：gcc ex3b.c -o ex3b && ./ex3b
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t  id;
    uint32_t value;
} Sensor;

/* TODO 1: 動態分配 3 個 Sensor
 *         初始化：id = 1,2,3；value = 100,200,300 */

/* TODO 2: 寫一個函式 find_sensor(Sensor *arr, int len, uint8_t id)
 *         回傳指向該 id 的指針，找不到回傳 NULL */
Sensor *find_sensor(Sensor *arr, int len, uint8_t id) {
    /* 填入程式碼 */
    return NULL;
}

/* TODO 3: 在 main 裡用 find_sensor 找 id=2 的 sensor，
 *         把它的 value 改成 999，再印出全部 */

int main() {
    return 0;
}
