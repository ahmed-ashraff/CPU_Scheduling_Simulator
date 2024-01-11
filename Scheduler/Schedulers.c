#include <stdlib.h>
#include <mmcobj.h>
#include "../Utilities.h"
#include "../Structers/SegTree.h"


void FCFS(int n, Process process[]) {
    qsort(process, n, sizeof(*process), compFCFS);
    waitingTime(n, process);
    //processesTable();
    ganttChart(n, process);
}

// (0, 7), (2, 4), (4, 1), (5, 4)
// (0, 7), (4, 1), (2, 4), (5, 4)
void SJF(int n, Process process[]) {
    qsort(process, n, sizeof(*process), compare_arrival_time);
    // Build the segment tree
    Node *root = build_segment_tree(0, n - 1);
    
}