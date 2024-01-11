//
// Created by Dev Ahmed on 12/9/2023.
//

#include <stdbool.h>

#ifndef CPU_SCHEDULING_SEGTREE_H
#define CPU_SCHEDULING_SEGTREE_H

#define MAX_N 100000

// Structure to store process information
typedef struct Process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Structure for a node in the segment tree
typedef struct Node {
    int min_burst; // Minimum burst time in the range
    int index; // Index of the process with the minimum burst time
    struct Node *left, *right; // Left and right child nodes
} Node;

//int n; // Total number of processes
Process processes[MAX_N];

Node* build_segment_tree(int low, int high);
int find_min_burst(Node *node, int low, int high, int query_low, int query_high);
int compare_arrival_time(const void *a, const void *b);

#endif //CPU_SCHEDULING_SEGTREE_H
