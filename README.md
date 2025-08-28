## How does it work?

1. Inside the functions `Task1` and `Task2`, there is an infinite loop.  
   Each task prints a message with a delay (`Task1` every 1 second, `Task2` every 0.5 seconds).  

2. In the `main` function, two tasks are created using `xTaskCreate`.  
   Each task is assigned its own function and stack size.  

3. Finally, the scheduler is started with `vTaskStartScheduler()`,  
   which runs both tasks according to their delays.
