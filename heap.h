//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()

        data[size] = idx; // stores the data size at index
        size++; // increments it by one
        upheap(size -1, weightArr);

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) { // checks of empty if it is returns -1
            return -1;
        }

        data[size - 1]  = data[0]; // data 0 is the root being the smallest node
        size--;
        downheap(0, weightArr);

        return -1; // place holder

    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 1 && weightArr[pos] < weightArr[pos / 2]) {
            swap(data[pos], data[pos / 2]);
            pos /= 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child

    }
};

#endif