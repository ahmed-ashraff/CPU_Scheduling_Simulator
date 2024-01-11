//
// Created by Dev Ahmed on 12/4/2023.
//
#include "Scheduler/Schedulers.h"
#include "Models/Process.h"

int main() {
    int n = 3;
    Process process[] = {
            {1, 0, 24},
            {2, 0, 3},
            {3, 0, 3},
    };

    FCFS(n, process);

    return 0;
}
