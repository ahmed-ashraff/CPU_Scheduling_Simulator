//
// Created by Dev Ahmed on 12/4/2023.
//

#ifndef CPU_SCHEDULING_UTILITIES_H
#define CPU_SCHEDULING_UTILITIES_H

#include "Models/Process.h"

void ganttChart(int n, Process process[]);
void waitingTime(int n, Process process[]);
void averageWaitingTime(int n, Process process[]);
void processesTable(int n, Process process[]);
int compFCFS(const void *a, const void *b);
int compSJF(const void *a, const void *b);

#endif //CPU_SCHEDULING_UTILITIES_H
