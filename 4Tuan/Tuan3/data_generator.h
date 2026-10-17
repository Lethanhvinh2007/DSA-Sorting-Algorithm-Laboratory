#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"

// Kiểm tra mảng đã có thứ tự tăng dần chưa (1: Đúng, 0: Sai)
int isSorted(int arr[], int n);

// In mảng ra màn hình
void printArray(const char* label, int arr[], int n);

// Sao chép mảng từ nguồn sang đích
void copyArray(const int src[], int dest[], int n);

// Kịch bản 1: Mảng ngẫu nhiên hoàn toàn
void generateRandomArray(int arr[], int n, int maxVal);

// Kịch bản 2: Mảng gần như đã sắp xếp (sắp xếp tăng dần rồi xáo trộn ngẫu nhiên 5% số cặp)
void generateNearlySortedArray(int arr[], int n);

// Kịch bản 3: Mảng sắp xếp ngược hoàn toàn (Worst case của Insertion/Bubble)
void generateReverseSortedArray(int arr[], int n);

// Kịch bản 4: Mảng có nhiều phần tử trùng lặp (giá trị hẹp từ 1 đến 10)
void generateManyDuplicatesArray(int arr[], int n);

#endif // DATA_GENERATOR_H
