#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cấu trúc lưu trữ thống kê kết quả chạy thuật toán
typedef struct {
    long long comparisons; // số phép so sánh giữa các phần tử
    long long moves;       // số phép di chuyển ô nhớ / hoán vị (swap & shift)
    double time_taken;     // thời gian chạy (mili-giây ms)
} SortStats;

// Hàm hoán vị 2 số nguyên
void swap(int *a, int *b);

// 1. Sắp xếp chèn (Insertion Sort)
SortStats insertionSort(int arr[], int n);

// 2. Sắp xếp chọn (Selection Sort)
SortStats selectionSort(int arr[], int n);

// 3. Sắp xếp nổi bọt có cờ dừng sớm (Bubble Sort Early-Exit)
SortStats bubbleSort(int arr[], int n);

// 4. Sắp xếp nhanh (QuickSort với Lomuto + Median of Three + Khử đệ quy đuôi)
int medianOfThree(int arr[], int low, int high, SortStats *stats);
int partition(int arr[], int low, int high, SortStats *stats);
void quickSortHelper(int arr[], int low, int high, SortStats *stats);
SortStats quickSort(int arr[], int n);

#endif // SORTING_ALGORITHMS_H
