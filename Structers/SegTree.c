//
// Created by Dev Ahmed on 12/9/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "SegTree.h"

Node* build_segment_tree(int low, int high) {
    if (low > high) return NULL;

    Node *node = (Node*)malloc(sizeof(Node));
    if (low == high) {
        node->min_burst = processes[low].burst_time;
        node->index = low;
        node->left = node->right = NULL;
    } else {
        int mid = (low + high) / 2;
        node->left = build_segment_tree(low, mid);
        node->right = build_segment_tree(mid + 1, high);
        node->min_burst = processes[node->left->index].burst_time < processes[node->right->index].burst_time ? node->left->index : node->right->index;
    }
    return node;
}

int find_min_burst(Node *node, int low, int high, int query_low, int query_high) {
    if (low > high || query_low > query_high || low > query_high || high < query_low)
        return -1;

    if (low >= query_low && high <= query_high) {
        return node->index;
    }

    int mid = (low + high) / 2;
    int left_index = find_min_burst(node->left, low, mid, query_low, query_high);
    int right_index = find_min_burst(node->right, mid + 1, high, query_low, query_high);

    if (left_index != -1 && right_index != -1) {
        return processes[left_index].burst_time < processes[right_index].burst_time
               ? left_index
               : right_index;
    } else if (left_index != -1) {
        return left_index;
    } else {
        return right_index;
    }
}

int compare_arrival_time(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;

    if (p1->arrival_time == p2->arrival_time)
        return p1->burst_time < p2->burst_time;
    return p1->arrival_time < p2->arrival_time;
}