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
        if (size >= 64) { // cant be more then 64 nodes so you check first
            return;
        }
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

            data[0]  = data[size]; // root becomes the last node
            size--;
            downheap(0, weightArr); //puts them in the correct order
        }

        return -1; // place holder

    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        int parent = (pos - 1) / 2;


        while (pos > 0) {
            if (weightArr[pos] < weightArr[parent]) { // the child has to be less than the parent
                swap(data[pos], data[parent]); // swaps it to the correct order
                pos = parent;
            }

        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        // downheap is moving the parrent to the childern
        while (pos == 0) {
            int left = 2 * pos;
            int right = 2 * pos + 1;
            // comapring the smaller child , to the arr data
            if (right < size && weightArr[data[right]] < weightArr[data[left]]) {
                // makes the swap if needs to be corrected in the right order
                swap(data[right], data[left]);
                pos = left;

            }
        }
    }
};

#endif