cmake_minimum_required(VERSION 3.25)
project(CPU_Scheduling C)

set(CMAKE_C_STANDARD 11)

add_executable(CPU_Scheduling Scheduler/Schedulers.c Utilities.c Utilities.h Main.c Models/Process.h Scheduler/Schedulers.h Structers/PriorityQueue.h Structers/PriorityQueue.c Structers/compareFunctions.h Structers/compareFunctions.c Structers/SegTree.h Structers/SegTree.c)
