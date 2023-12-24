#include <iostream>
#include "heap.h"

int main() {
    std::vector<int> data = {9, 2, 25, 48, 15, 14, 21, 3, 8};
    std::cout << "Original array:" << std::endl;
    for (int i : data)
        std::cout << i << ' ';
    std::cout << std::endl;

    // Build heap
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);

    std::cout << "Check if the data structure is actually a heap:" << std::endl;
    bool isMax = isMaxHeap(data, n, 0);
    bool isMin = !isMax ? isMinHeap(data, n, 0) : false;

    std::cout << "Is max heap: " << std::boolalpha << isMax << std::endl;
    std::cout << "Is min heap: " << std::boolalpha << isMin << std::endl;

    // If both are false, the data structure is not a heap
    if (!isMax && !isMin) {
        std::cout << "The data structure is not a heap." << std::endl;
    }

    // Sort array using heap sort
    heapSort(data);

    std::cout << "Sorted array using heap sort:" << std::endl;
    for (int i : data)
        std::cout << i << ' ';
    std::cout << std::endl;

    std::cout << "Heap depth: " << heapDepth(data) << std::endl;

    return 0;
}
