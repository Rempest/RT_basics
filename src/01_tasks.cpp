#include <cstdio>
#include "FreeRTOS.h"
#include "task.h"

void Task1(void* parameters)
{
    (void)parameters;
    for (;;)
    {
        std::printf("Task 1 is running\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void Task2(void* parameters)
{
    (void)parameters;
    for (;;)
    {
        std::printf("Task 2 is running\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main()
{
    BaseType_t task1_result = xTaskCreate(
        Task1,
        "Task1",
        1000,
        nullptr,
        1,
        nullptr
    );

    BaseType_t task2_result = xTaskCreate(
        Task2,
        "Task2",
        1000,
        nullptr,
        1,
        nullptr
    );

    if (task1_result != pdPASS || task2_result != pdPASS)
    {
        std::fprintf(stderr, "Failed to create tasks\n");
        return 1;
    }

    vTaskStartScheduler();
    for (;;)
    {
    }
}
