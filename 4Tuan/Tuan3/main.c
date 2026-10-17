#include <stdio.h>
#include "sorting_algorithms.c"
#include "data_generator.c"
#include "benchmark.c"

int main(void)
{
    printf("--- BAO CAO TUAN 3: BENCHMARK DO DAC VA XUAT CSV ---\n");
    printf("Sinh vien: Le Thanh Vinh - MSSV: 25110075\n\n");

    runFullBenchmark("results/sorting_benchmark_results.csv");

    printf("----------------------------------------\n");
    printf("Ket qua: Hoan tat do dac 64 kịch ban va xuat file CSV thanh cong!\n");
    return 0;
}
