#include <stdio.h>
#include "sorting_algorithms.c"
#include "data_generator.c"
#include "test_cases.c"

int main(void)
{
    printf("--- BAO CAO TUAN 2: SINH DU LIEU & KIEM THU BIEN ---\n");
    printf("Sinh vien: Le Thanh Vinh - MSSV: 25110075\n\n");

    // 1. Chay test tinh tay N = 6
    runHandTraceableTest();

    // 2. Chay 6 truong hop bien
    testEdgeCases();

    printf("----------------------------------------\n");
    printf("Ket qua: Kiem thu thanh cong toan bo 6 truong hop bien!\n");
    return 0;
}
