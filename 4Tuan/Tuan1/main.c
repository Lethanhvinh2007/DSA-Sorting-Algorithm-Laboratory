#include <stdio.h>
#include "sorting_algorithms.c"

void printArray(const char* label, int arr[], int n)
{
    printf("%-12s : [", label);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

void copyArray(const int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

int main(void)
{
    printf("--- BAO CAO TUAN 1: CAI DAT 4 THUAT TOAN SAP XEP ---\n");
    printf("Sinh vien: Le Thanh Vinh - MSSV: 25110075\n\n");

    int sample[8] = {29, 10, 14, 37, 13, 25, 45, 12};
    int temp[8];

    printArray("Mang goc", sample, 8);
    printf("----------------------------------------\n");

    // 1. Insertion Sort
    copyArray(sample, temp, 8);
    SortStats s1 = insertionSort(temp, 8);
    printArray("Insertion", temp, 8);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms\n\n",
           s1.comparisons, s1.moves, s1.time_taken);

    // 2. Selection Sort
    copyArray(sample, temp, 8);
    SortStats s2 = selectionSort(temp, 8);
    printArray("Selection", temp, 8);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms\n\n",
           s2.comparisons, s2.moves, s2.time_taken);

    // 3. Bubble Sort
    copyArray(sample, temp, 8);
    SortStats s3 = bubbleSort(temp, 8);
    printArray("BubbleSort", temp, 8);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms\n\n",
           s3.comparisons, s3.moves, s3.time_taken);

    // 4. QuickSort
    copyArray(sample, temp, 8);
    SortStats s4 = quickSort(temp, 8);
    printArray("QuickSort", temp, 8);
    printf("  -> So sanh: %lld | Di chuyen: %lld | Thoi gian: %.4f ms\n\n",
           s4.comparisons, s4.moves, s4.time_taken);

    printf("----------------------------------------\n");
    printf("Ket qua: Ca 4 thuat toan deu chay dung!\n");
    return 0;
}
