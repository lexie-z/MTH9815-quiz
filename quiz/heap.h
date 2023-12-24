#ifndef QUIZ_HEAP_H
#define QUIZ_HEAP_H
#include <vector>

void heapify(std::vector<int>& arr, int n, int i);
void heapSort(std::vector<int>& arr);
int heapDepth(const std::vector<int>& arr);
bool isMaxHeap(const std::vector<int>& arr, int n, int i=0);
bool isMinHeap(const std::vector<int>& arr, int n, int i=0);

#endif //QUIZ_HEAP_H
