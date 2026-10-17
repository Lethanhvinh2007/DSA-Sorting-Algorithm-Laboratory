# BÁO CÁO TIẾN ĐỘ TUẦN 3: ĐO ĐẠC THỰC NGHIỆM & PHÂN TÍCH BIỂU ĐỒ
**Đề tài:** Sorting Algorithm Laboratory: Insertion, Selection, Bubble, Quicksort  
**Giảng viên hướng dẫn:** Thầy Huỳnh Xuân Phụng  
**Sinh viên thực hiện:** Lê Thanh Vinh - MSSV: 25110075  
**Giai đoạn:** Tuần 3 / 4 tuần

---

## 1. Mục tiêu công việc trong Tuần 3
- Chạy toàn bộ ma trận đo đạc thực nghiệm:
  - 4 thuật toán: Insertion, Selection, Bubble, QuickSort (Med-3).
  - 4 kịch bản dữ liệu: Random, Nearly-Sorted, Reverse-Sorted, Many-Duplicates.
  - 4 kích thước: $N = 100, 1.000, 10.000, 100.000$.
  - Tổng cộng $4 \times 4 \times 4 = 64$ lần đo độc lập.
- Tự động xuất toàn bộ số liệu ra file `results/sorting_benchmark_results.csv`.
- Dựng bảng PivotTable và biểu đồ đường có thang đo Logarit trong Excel (`sorting_benchmark_charts.xlsx`).

---

## 2. Nhận xét thực nghiệm then chốt
- **Tại $N = 100.000$ (Mảng ngẫu nhiên):**
  - **QuickSort:** Chỉ tốn **10.66 ms** ($O(N \log N)$).
  - **Insertion Sort:** Mất **2.592 ms** (~2.6 giây).
  - **Selection Sort:** Mất **12.672 ms** (~12.6 giây).
  - **Bubble Sort:** Mất tới **38.230 ms** (~38.2 giây).
  - Chênh lệch tốc độ giữa QuickSort và Bubble Sort lên tới **gần 3.600 lần**, chứng minh sự áp đảo của $O(N \log N)$.
- **Trên mảng gần như đã sắp xếp (Nearly-Sorted):**
  - Insertion Sort tiệm cận $O(N)$, chạy chỉ mất **0.31 ms**, vượt qua cả QuickSort.
