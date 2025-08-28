#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
//first function
void Task1 (void *ptrParametrs){
    for(;;) {
        printf("Task1 is running\n");
//ticks for 1 seconds
        vTaskDelay(pdMS_TO_TICK(1000));
    }
}
//second function
void Task2(void *ptrParametrs2) {
    for(true){
        printf("Task2 is running\n");
//ticks 0.5 seconds
    vTaskDelay(pdMS_TO_TICK(500));
}
  }
//main function
int main (void) {
    //creat tasks
    xTaskCreate(Task1, "Task1", 1000, NULL, 1, NULL);
    xTaskCreate(Task2, "Task2", 500, NULL, 1, NULL);
    //starting the scheduler
    vTaskStartScheduler();
    for(;;);
}
