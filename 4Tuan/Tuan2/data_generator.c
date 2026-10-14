#include "data_generator.h"

// Kiểm tra mảng đã có thứ tự tăng dần chưa (1: Đúng, 0: Sai)
int isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return 0;
        }
    }
    return 1;
}

// In mảng ra màn hình (thụt lề label 12 ký tự)
void printArray(const char* label, int arr[], int n)
{
    printf("%-12s : [", label);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");
}

// Sao chép mảng từ nguồn sang đích
void copyArray(const int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

// Kịch bản 1: Mảng ngẫu nhiên hoàn toàn
void generateRandomArray(int arr[], int n, int maxVal)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % maxVal;
    }
}

// Kịch bản 2: Mảng gần như đã sắp xếp (sắp xếp tăng dần rồi xáo trộn ngẫu nhiên 5% số cặp)
void generateNearlySortedArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int swapsCount = (int)(n * 0.05);
    if (swapsCount < 1 && n > 1)
    {
        swapsCount = 1;
    }

    for (int k = 0; k < swapsCount; k++)
    {
        int i = rand() % n;
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }
}

// Kịch bản 3: Mảng sắp xếp ngược hoàn toàn (Worst case của Insertion/Bubble)
void generateReverseSortedArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}

// Kịch bản 4: Mảng có nhiều phần tử trùng lặp (giá trị hẹp từ 1 đến 10)
void generateManyDuplicatesArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 10) + 1;
    }
}
