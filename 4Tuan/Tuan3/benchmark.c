#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"
#include "sorting_algorithms.h"
#include "data_generator.h"

// Chay toan bo ma tran do dac (4 thuat toan x 4 kich ban x 4 quy mo N)
void runFullBenchmark(const char* csvPath)
{
    printf("\n--- TIEN HANH DO DAC BENCHMARK (N = 100, 1.000, 10.000, 100.000) ---\n");

    FILE *f = fopen(csvPath, "w");
    if (!f)
    {
        printf("Khong the mo file CSV de ghi: %s\n", csvPath);
        return;
    }

    // Tieu de cot file CSV
    fprintf(f, "Algorithm,Data_Type,Size,Comparisons,Swaps,Time_ms\n");

    const int sizes[] = {100, 1000, 10000, 100000};
    const int numSizes = 4;

    const char* dataTypes[] = {
        "Random (Ngau nhien)",
        "Nearly-Sorted (Gan nhu da sap xep)",
        "Reverse-Sorted (Sap xep nguoc)",
        "Many-Duplicates (Nhieu trung lap)"
    };

    srand((unsigned int)time(NULL));

    printf("\nBat dau thuc nghiem tren 4 kich ban du lieu va ghi nhan file CSV...\n");
    fflush(stdout);

    for (int dt = 0; dt < 4; dt++)
    {
        printf("\n>>> KICH BAN: %s <<<\n", dataTypes[dt]);
        printf("%-18s | %-8s | %-15s | %-15s | %-12s\n",
               "Thuat toan", "Kich thuoc", "So phep so sanh", "So phep hoan vi", "Thoi gian (ms)");
        printf("------------------------------------------------------------------------------\n");
        fflush(stdout);

        for (int s = 0; s < numSizes; s++)
        {
            int n = sizes[s];

            int *original = (int*)malloc((size_t)n * sizeof(int));
            int *arr = (int*)malloc((size_t)n * sizeof(int));

            if (!original || !arr)
            {
                printf("Loi cap phat bo nho RAM cho N = %d\n", n);
                if (original) free(original);
                if (arr) free(arr);
                continue;
            }

            // Sinh du lieu theo kich ban
            if (dt == 0) generateRandomArray(original, n, 1000000);
            else if (dt == 1) generateNearlySortedArray(original, n);
            else if (dt == 2) generateReverseSortedArray(original, n);
            else generateManyDuplicatesArray(original, n);

            // 1. Insertion Sort
            copyArray(original, arr, n);
            SortStats s_ins = insertionSort(arr, n);
            fprintf(f, "Insertion Sort,%s,%d,%lld,%lld,%.4f\n",
                    dataTypes[dt], n, s_ins.comparisons, s_ins.moves, s_ins.time_taken);
            printf("%-18s | %-8d | %-15lld | %-15lld | %-12.4f\n",
                   "Insertion Sort", n, s_ins.comparisons, s_ins.moves, s_ins.time_taken);
            fflush(stdout);
            fflush(f);

            // 2. Selection Sort
            copyArray(original, arr, n);
            SortStats s_sel = selectionSort(arr, n);
            fprintf(f, "Selection Sort,%s,%d,%lld,%lld,%.4f\n",
                    dataTypes[dt], n, s_sel.comparisons, s_sel.moves, s_sel.time_taken);
            printf("%-18s | %-8d | %-15lld | %-15lld | %-12.4f\n",
                   "Selection Sort", n, s_sel.comparisons, s_sel.moves, s_sel.time_taken);
            fflush(stdout);
            fflush(f);

            // 3. Bubble Sort
            copyArray(original, arr, n);
            SortStats s_bub = bubbleSort(arr, n);
            fprintf(f, "Bubble Sort,%s,%d,%lld,%lld,%.4f\n",
                    dataTypes[dt], n, s_bub.comparisons, s_bub.moves, s_bub.time_taken);
            printf("%-18s | %-8d | %-15lld | %-15lld | %-12.4f\n",
                   "Bubble Sort", n, s_bub.comparisons, s_bub.moves, s_bub.time_taken);
            fflush(stdout);
            fflush(f);

            // 4. QuickSort (Med-3)
            copyArray(original, arr, n);
            SortStats s_quick = quickSort(arr, n);
            fprintf(f, "QuickSort (Med-3),%s,%d,%lld,%lld,%.4f\n",
                    dataTypes[dt], n, s_quick.comparisons, s_quick.moves, s_quick.time_taken);
            printf("%-18s | %-8d | %-15lld | %-15lld | %-12.4f\n",
                   "QuickSort (Med-3)", n, s_quick.comparisons, s_quick.moves, s_quick.time_taken);
            fflush(stdout);
            fflush(f);

            printf("------------------------------------------------------------------------------\n");
            fflush(stdout);

            free(original);
            free(arr);
        }
    }

    fclose(f);
    printf("\nDa hoan tat Benchmark! Ket qua da duoc xuat ra file CSV:\n");
    printf("-> %s\n\n", csvPath);
}
