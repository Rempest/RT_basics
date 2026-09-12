cmake_minimum_required(VERSION 3.16)

project(freertos_basics LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    freertos_kernel
    GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
    GIT_TAG main
)

FetchContent_MakeAvailable(freertos_kernel)

add_executable(01_tasks
    src/01_tasks.cpp
)

add_executable(02_priorities
    src/02_priorities.cpp
)

add_executable(03_queue
    src/03_queue.cpp
)

add_executable(04_periodic
    src/04_periodic.cpp)

target_link_libraries(01_tasks
    PRIVATE
    freertos_kernel
)

target_link_libraries(02_priorities
    PRIVATE
    freertos_kernel
)

target_link_libraries(03_queue
    PRIVATE
    freertos_kernel
)

target_link_libraries(04_periodic
    PRIVATE
    freertos_kernel
)
