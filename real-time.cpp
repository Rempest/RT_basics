#include <cstdio>
#include <rclcpp/rclcpp.hpp>
#include "FreeRTOS.h"
#include "task.h"
#include <cstdio>

// Простые задачи: печатают сообщение и "спят"
static void TaskBlink(void* pvParameters) {
    const char* name = static_cast<const char*>(pvParameters);
    for (;;) {
        std::printf("%s: tick\n", name);
        vTaskDelay(pdMS_TO_TICKS(500)); // 500 ms
    }
}

int main() {
    // Создаём две задачи
    xTaskCreate(
        TaskBlink,            // функция задачи
        "Blink1",             // имя (для отладки)
        configMINIMAL_STACK_SIZE + 128, // стек (слегка больше минимального)
        (void*)"TaskA",       // параметр задачи
        tskIDLE_PRIORITY + 1, // приоритет
        nullptr               // хэндл (не нужен)
    );

    xTaskCreate(
        TaskBlink,
        "Blink2",
        configMINIMAL_STACK_SIZE + 128,
        (void*)"TaskB",
        tskIDLE_PRIORITY + 1,
        nullptr
    );

    // Запуск планировщика — после этого main обычно не возвращается
    vTaskStartScheduler();

    // Если планировщик остановился — попадём сюда (обычно ошибка)
    for (;;) {}
    return 0;
}
