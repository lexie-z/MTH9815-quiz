#include "heap.h"
#include <cmath>

//Build a subtree rooted at i using max heap
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

//Use heapify to sort the entire array
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        // Call heapify on the remaining heap
        heapify(arr, i, 0);
    }
}

//Determine how many levels deep a heap is
int heapDepth(const std::vector<int>& arr) {
    return std::ceil(std::log2(arr.size() + 1)) - 1;
}

bool isMaxHeap(const std::vector<int>& arr, int n, int i) {
    if (i >= n) return true;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //whether the current node i is larger than its left and right children—if not, it's not a max-heap

    if (left < n && arr[i] < arr[left]) return false;
    if (right < n && arr[i] < arr[right]) return false;

    return isMaxHeap(arr, n, left) && isMaxHeap(arr, n, right);
}

bool isMinHeap(const std::vector<int>& arr, int n, int i) {
    if (i >= n) return true;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //whether the current node i is smaller than its left and right children—if not, it's not a min-heap

    if (left < n && arr[i] > arr[left]) return false;
    if (right < n && arr[i] > arr[right]) return false;

    return isMinHeap(arr, n, left) && isMinHeap(arr, n, right);
}
