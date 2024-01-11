//
// Created by Dev Ahmed on 12/4/2023.
//

#ifndef CPU_SCHEDULING_PROCESS_H
#define CPU_SCHEDULING_PROCESS_H

typedef int UnitTime;

typedef struct {
    int processId;
    UnitTime arrivalTime, burstTime, responseTime, waitingTime, turnAroundTime, completionTime;
} Process;

typedef struct {
    int processId;
    UnitTime arrivalTime, burstTime;
} readyProcess;

#endif //CPU_SCHEDULING_PROCESS_H
