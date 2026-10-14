#include <stdio.h>
#include "test_cases.h"
#include "sorting_algorithms.h"
#include "data_generator.h"

// 1. Chạy test case nhỏ tính tay được (Hand-traceable example: [5, 2, 4, 6, 1, 3])
void runHandTraceableTest(void)
{
    printf("--- 1. KIEM THU MAU TINH TAY DUOC (N = 6) ---\n");

    int initial[6] = {5, 2, 4, 6, 1, 3};
    int temp[6];

    printArray("Mang ban dau", initial, 6);
    printf("----------------------------------------\n");

    // 1. Insertion Sort
    copyArray(initial, temp, 6);
    SortStats s1 = insertionSort(temp, 6);
    printArray("Insertion", temp, 6);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms | Ket qua: %s\n\n",
           s1.comparisons, s1.moves, s1.time_taken,
           isSorted(temp, 6) ? "Sort thanh cong" : "Khong sort duoc");

    // 2. Selection Sort
    copyArray(initial, temp, 6);
    SortStats s2 = selectionSort(temp, 6);
    printArray("Selection", temp, 6);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms | Ket qua: %s\n\n",
           s2.comparisons, s2.moves, s2.time_taken,
           isSorted(temp, 6) ? "Sort thanh cong" : "Khong sort duoc");

    // 3. Bubble Sort
    copyArray(initial, temp, 6);
    SortStats s3 = bubbleSort(temp, 6);
    printArray("BubbleSort", temp, 6);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms | Ket qua: %s\n\n",
           s3.comparisons, s3.moves, s3.time_taken,
           isSorted(temp, 6) ? "Sort thanh cong" : "Khong sort duoc");

    // 4. QuickSort
    copyArray(initial, temp, 6);
    SortStats s4 = quickSort(temp, 6);
    printArray("QuickSort", temp, 6);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms | Ket qua: %s\n",
           s4.comparisons, s4.moves, s4.time_taken,
           isSorted(temp, 6) ? "Sort thanh cong" : "Khong sort duoc");
    printf("----------------------------------------\n\n");
}

// 2. Chạy kiểm thử 6 trường hợp biên (Edge cases)
void testEdgeCases(void)
{
    printf("--- 2. KIEM THU 6 TRUONG HOP BIEN (EDGE CASES) ---\n");

    // Case 1: Mảng rỗng (n = 0)
    int c1[1];
    insertionSort(c1, 0);
    selectionSort(c1, 0);
    bubbleSort(c1, 0);
    quickSort(c1, 0);
    printf("1. Mang rong (n = 0): %s\n", 
           isSorted(c1, 0) ? "Sort thanh cong" : "Khong sort duoc");

    // Case 2: Mảng 1 phần tử (n = 1)
    int c2[] = {7};
    insertionSort(c2, 1);
    printf("2. Mang 1 phan tu (n = 1): %s (Gia tri: %d)\n", 
           isSorted(c2, 1) ? "Sort thanh cong" : "Khong sort duoc", c2[0]);

    // Case 3: Mảng đã sắp xếp sẵn (Already sorted)
    int c3[] = {1, 2, 3, 4, 5};
    SortStats s_bubble_sorted = bubbleSort(c3, 5);
    printf("3. Mang da co thu tu (n = 5): %s (Bubble so sanh: %lld)\n", 
           isSorted(c3, 5) ? "Sort thanh cong" : "Khong sort duoc", s_bubble_sorted.comparisons);

    // Case 4: Mảng sắp xếp ngược hoàn toàn (Reverse sorted)
    int c4[] = {5, 4, 3, 2, 1};
    quickSort(c4, 5);
    printf("4. Mang giam dan (n = 5): %s\n", 
           isSorted(c4, 5) ? "Sort thanh cong" : "Khong sort duoc");

    // Case 5: Mảng toàn bộ phần tử trùng lặp (All duplicates)
    int c5[] = {3, 3, 3, 3, 3};
    quickSort(c5, 5);
    printf("5. Mang trung lap tat ca (n = 5): %s\n", 
           isSorted(c5, 5) ? "Sort thanh cong" : "Khong sort duoc");

    // Case 6: Mảng 2 phần tử nghịch đảo
    int c6[] = {9, 2};
    quickSort(c6, 2);
    printf("6. Mang 2 phan tu nghich dao: %s [%d, %d]\n\n", 
           isSorted(c6, 2) ? "Sort thanh cong" : "Khong sort duoc", c6[0], c6[1]);
}
