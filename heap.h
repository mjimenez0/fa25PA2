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

        if (size > 0) {

            data[size - 1]  = data[0]; // data 0 is the root being the smallest node
            size--;
            downheap(0, weightArr);
        }

        return -1; // place holder

    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        int parent = (pos - 1) / 2;;
        // leftChild = 2 * pos;
        // rightChild = 2 * pos + 1;

        while (pos > 0) {
            if (weightArr[pos] < weightArr[parent]) { // the child has to be less than the parent
                swap(data[pos], data[parent]); // swaps it to the correct order
            }

        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos > 0) {
            weightArr[pos] = 2 * pos;
            weightArr[pos] = 2 * (pos + 1);
        }
    }
};

#endif