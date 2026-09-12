#include <cstdio>
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

struct SensorData
{
    float distance;
    float velocity;
};

QueueHandle_t sensor_queue = nullptr;
void SensorTask(void* parameters)
{
    (void)parameters;
    float distance = 1.0f;
    float velocity = 0.5f;

    for (;;)
    {
        SensorData data{
            distance,
            velocity
        };

        if (xQueueSend(sensor_queue, &data, pdMS_TO_TICKS(100)) == pdPASS)
        {
            std::printf(
                "[SENSOR] distance=%.2f m, velocity=%.2f m/s\n",
                data.distance,
                data.velocity
            );
        }
        else
        {
            std::printf("[SENSOR] Queue is full\n");
        }
        distance += 0.1f;
        velocity += 0.05f;
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void ControlTask(void* parameters)
{
    (void)parameters;
    SensorData data{};

    for (;;)
    {
        if (xQueueReceive(sensor_queue, &data, portMAX_DELAY) == pdPASS)
        {
            std::printf(
                "[CONTROL] received distance=%.2f m, velocity=%.2f m/s\n",
                data.distance,
                data.velocity
            );
        }
    }
}

int main()
{
    sensor_queue = xQueueCreate(5, sizeof(SensorData));
    if (sensor_queue == nullptr)
    {
        std::fprintf(stderr, "Failed to create sensor queue\n");
        return 1;
    }

    BaseType_t sensor_result = xTaskCreate(
        SensorTask,
        "SensorTask",
        1000,
        nullptr,
        2,
        nullptr
    );

    BaseType_t control_result = xTaskCreate(
        ControlTask,
        "ControlTask",
        1000,
        nullptr,
        3,
        nullptr
    );

    if (
        sensor_result != pdPASS ||
        control_result != pdPASS
    )
    {
        std::fprintf(stderr, "Failed to create tasks\n");
        vQueueDelete(sensor_queue);
        return 1;
    }

    vTaskStartScheduler();
    for (;;)
    {
    }
}
