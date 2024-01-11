//
// Created by Dev Ahmed on 12/4/2023.
//

#include <stdio.h>
#include "Scheduler/Schedulers.h"

void processesTable(int n, Process process[]) {
    printf("Process Table: \n");


}

void ganttChart(int n, Process process[]) {
    printf("Gantt Chart: \n");

    printf(" ");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < process[i].burstTime; ++j) {
            printf("__");
        }
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * process[i].burstTime-1; ++j) {
            if (j == process[i].burstTime)
                printf("P%d", process[i].processId);
            else
                printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < process[i].burstTime; ++j) {
            printf("__");
        }
        printf(" ");
    }

    printf("\n0");
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2 * process[i-1].burstTime-1; ++j) {
            printf(" ");
        }
        printf("%d", process[i].waitingTime);
    }
}

void waitingTime(int n, Process process[]) {
    //printf("Waiting Time For Processes: \nP%d = %d\n", process[0].processId, 0);
    int sum=0;
    process[0].waitingTime = 0;
    for (int i = 1; i <= n; ++i) {
        sum += process[i-1].burstTime;
        //printf("P%d = %d\n", process[i].processId, sum);
        process[i].waitingTime = sum;
    }
}

void averageWaitingTime(int n, Process process[]) {
    int sum = 0, k = 0;
    printf("Average Waiting Time For Processes: ");
    for (int i = 0; i < n-1; ++i) {
        k += process[i].burstTime;
        sum += k;
    }
    printf("%d", (sum / n));
}

int compFCFS(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;

    return (p1->arrivalTime <= p2->arrivalTime);
}
