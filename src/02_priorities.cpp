#include <cstdio>
#include "FreeRTOS.h"
#include "task.h"

void HighPriorityTask(void* parameters)
{
    (void)parameters;
    for (;;)
    {
        std::printf("[HIGH] High-priority task is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void MediumPriorityTask(void* parameters)
{
    (void)parameters;
    for (;;)
    {
        std::printf("[MEDIUM] Medium-priority task is running\n");
        vTaskDelay(pdMS_TO_TICKS(700));
    }
}

void LowPriorityTask(void* parameters)
{
    (void)parameters;
    for (;;)
    {
        std::printf("[LOW] Low-priority task is running\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main()
{
    BaseType_t high_result = xTaskCreate(
        HighPriorityTask,
        "HighTask",
        1000,
        nullptr,
        3,
        nullptr
    );

    BaseType_t medium_result = xTaskCreate(
        MediumPriorityTask,
        "MediumTask",
        1000,
        nullptr,
        2,
        nullptr
    );

    BaseType_t low_result = xTaskCreate(
        LowPriorityTask,
        "LowTask",
        1000,
        nullptr,
        1,
        nullptr
    );

    if (
        high_result != pdPASS ||
        medium_result != pdPASS ||
        low_result != pdPASS
    )
    {
        std::fprintf(stderr, "Failed to create one or more tasks\n");
        return 1;
    }

    vTaskStartScheduler();
    for (;;)
    {
    }
}
