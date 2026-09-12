#include <cstdio>
#include "FreeRTOS.h"
#include "task.h"

void PeriodicTask(void* parameters)
{
    (void)parameters;
    constexpr TickType_t period = pdMS_TO_TICKS(100);
    TickType_t last_wake_time = xTaskGetTickCount();

    for (;;)
    {
        std::printf("[CONTROL] periodic control cycle\n");
        vTaskDelayUntil(
            &last_wake_time,
            period
        );
    }
}

int main()
{
    BaseType_t result = xTaskCreate(
        PeriodicTask,
        "PeriodicControl",
        1000,
        nullptr,
        3,
        nullptr
    );

    if (result != pdPASS)
    {
        std::fprintf(stderr, "Failed to create periodic task\n");
        return 1;
    }

    vTaskStartScheduler();
    for (;;)
    {
    }
}
