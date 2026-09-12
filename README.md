# FreeRTOS Basics

A small C++ project for learning the fundamentals of real-time task scheduling and inter-task communication using FreeRTOS.

## Overview

This project demonstrates several core FreeRTOS concepts through small, independent experiments.
The goal is to understand how tasks are created, scheduled, prioritized, synchronized, and executed periodically in a real-time system.

## Experiments

### 01 — Tasks

Demonstrates:

* task creation with `xTaskCreate()`
* infinite task loops
* task delays with `vTaskDelay()`

Two tasks run with different periods:

```text
Task 1 → 1000 ms
Task 2 → 500 ms
```

### 02 — Task Priorities

Demonstrates how FreeRTOS uses task priorities when selecting which ready task should execute.

```text
High priority   → 3
Medium priority → 2
Low priority    → 1
```

### 03 — Queue Communication

Demonstrates communication between tasks using a FreeRTOS queue.

```text
Sensor Task
     │
     ▼
   Queue
     │
     ▼
Control Task
```

A sensor task produces data and sends it through the queue, while the control task receives and processes it.

### 04 — Periodic Execution

Demonstrates periodic task execution using `vTaskDelayUntil()`.

```text
t0       t1       t2       t3
│        │        │        │
▼        ▼        ▼        ▼
CONTROL  CONTROL  CONTROL  CONTROL
```

The target period for the control task is 100 ms.

## Project Structure

```text
RT_basics/
├── README.md
├── CMakeLists.txt
├── .gitignore
└── src/
    ├── 01_tasks.cpp
    ├── 02_priorities.cpp
    ├── 03_queue.cpp
    └── 04_periodic.cpp
```

## Requirements

* C++
* CMake
* FreeRTOS Kernel
* A compatible FreeRTOS port/toolchain

## Build

```bash
git clone https://github.com/Rempest/freertos-basics.git
cd freertos-basics

mkdir build
cd build

cmake ..
cmake --build .
```

## Concepts Covered

```text
FreeRTOS
   │
   ├── Tasks
   ├── Task Priorities
   ├── Delays
   ├── Queues
   └── Periodic Execution
```

These concepts form part of the foundation for real-time embedded and robotic systems.

## Learning Goal

The project is focused on understanding the basic mechanisms behind real-time task execution before moving to more complex robotic and embedded systems.

> **This is an educational project created for learning and experimentation with FreeRTOS and real-time systems.**
