#include "sorting_algorithms.h"

// Hàm hoán vị 2 số nguyên
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#pragma region 1. Insertion Sort
// Sắp xếp chèn: duyệt từ phần tử thứ 2, trượt các phần tử lớn hơn key sang phải
SortStats insertionSort(int arr[], int n)
{
    SortStats stats = {0, 0, 0.0};
    if (n <= 1)
    {
        return stats;
    }

    clock_t start = clock();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            stats.comparisons++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j]; // trượt ô sang phải
                stats.moves++;       // mỗi lần trượt tính là 1 shift
                j--;
            }
            else
            {
                break;
            }
        }
        // (j < 0 hoặc <= key thì chèn ngay vào trước ô j ở đợt while trước: j + 1)
        arr[j + 1] = key;
    }

    clock_t end = clock();
    stats.time_taken = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC; // đổi ra ms
    return stats;
}
#pragma endregion

#pragma region 2. Selection Sort
// Sắp xếp chọn: tìm giá trị nhỏ nhất trong đoạn còn lại rồi đổi chỗ với vị trí i
SortStats selectionSort(int arr[], int n)
{
    SortStats stats = {0, 0, 0.0};
    if (n <= 1)
    {
        return stats;
    }

    clock_t start = clock();

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            stats.comparisons++;
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(&arr[i], &arr[minIdx]);
            stats.moves++; // tính 1 lần swap
        }
    }

    clock_t end = clock();
    stats.time_taken = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    return stats;
}
#pragma endregion

#pragma region 3. Bubble Sort Early-Exit
// Sắp xếp nổi bọt: có cờ swapped để dừng sớm nếu mảng đã có thứ tự
SortStats bubbleSort(int arr[], int n)
{
    SortStats stats = {0, 0, 0.0};
    if (n <= 1)
    {
        return stats;
    }

    clock_t start = clock();

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // cờ kiểm tra xem lượt này có phần tử nào bị đổi chỗ không
        for (int j = 0; j < n - i - 1; j++)
        {
            stats.comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                stats.moves++; // tính 1 lần swap
                swapped = 1;
            }
        }
        // Nếu qua 1 lượt quét mà không có hoán vị nào thì mảng đã có thứ tự -> dừng sớm
        if (swapped == 0)
        {
            break;
        }
    }

    clock_t end = clock();
    stats.time_taken = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    return stats;
}
#pragma endregion

#pragma region 4. QuickSort Lomuto + Median of Three
// Chiến lược Median of Three: lấy trung vị của low, mid, high rồi đưa về arr[high] làm pivot
int medianOfThree(int arr[], int low, int high, SortStats *stats)
{
    if (high - low >= 2)
    {
        int mid = low + (high - low) / 2;

        stats->comparisons++;
        if (arr[low] > arr[mid])
        {
            swap(&arr[low], &arr[mid]);
            stats->moves++;
        }

        stats->comparisons++;
        if (arr[low] > arr[high])
        {
            swap(&arr[low], &arr[high]);
            stats->moves++;
        }

        stats->comparisons++;
        if (arr[mid] > arr[high])
        {
            swap(&arr[mid], &arr[high]);
            stats->moves++;
        }

        // Đưa phần tử trung vị về high để đóng vai trò làm Pivot cho phân hoạch Lomuto
        swap(&arr[mid], &arr[high]);
        stats->moves++;
    }
    return high;
}

// Phân hoạch Lomuto với Pivot đã được đặt ở arr[high]
int partition(int arr[], int low, int high, SortStats *stats)
{
    medianOfThree(arr, low, high, stats);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        stats->comparisons++;
        if (arr[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&arr[i], &arr[j]);
                stats->moves++;
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    stats->moves++;
    return i + 1; // vị trí chuẩn xác của Pivot
}

// Khử đệ quy đuôi (Tail-Call Optimization): đệ quy nửa nhỏ hơn trước, nửa lớn lặp vòng while
// Giúp khống chế call stack tối đa O(log N), hoàn toàn không lo tràn stack khi N = 100.000
void quickSortHelper(int arr[], int low, int high, SortStats *stats)
{
    while (low < high)
    {
        int p = partition(arr, low, high, stats);

        if (p - low < high - p)
        {
            quickSortHelper(arr, low, p - 1, stats);
            low = p + 1;
        }
        else
        {
            quickSortHelper(arr, p + 1, high, stats);
            high = p - 1;
        }
    }
}

// Hàm bao ngoài đồng bộ signature để đo thời gian
SortStats quickSort(int arr[], int n)
{
    SortStats stats = {0, 0, 0.0};
    if (n <= 1)
    {
        return stats;
    }

    clock_t start = clock();
    quickSortHelper(arr, 0, n - 1, &stats);
    clock_t end = clock();

    stats.time_taken = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    return stats;
}
#pragma endregion
