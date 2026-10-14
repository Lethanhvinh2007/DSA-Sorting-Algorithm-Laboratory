# Sorting Algorithm Laboratory

Đồ án môn học: Cấu trúc dữ liệu và Giải thuật (DSA)  
Trường: Đại học Công Nghệ Kỹ thuật TP.HCM (HCMUTE)  
Giảng viên hướng dẫn: TS. Huỳnh Xuân Phụng  
Sinh viên thực hiện: Lê Thanh Vinh - MSSV: 25110075  

---

### 1. Giới thiệu đề tài
Chương trình thực nghiệm và so sánh các thuật toán sắp xếp kinh điển, được xây dựng trên nền tảng ngôn ngữ C.

Trong giai đoạn đầu (Tuần 1), dự án tập trung hiện thực hóa và kiểm thử tính đúng đắn của 4 thuật toán sắp xếp cốt lõi trên mảng số nguyên:

* `Insertion Sort`: Sắp xếp chèn, duyệt mảng con và trượt các phần tử lớn hơn khóa sang phải để chèn vào vị trí thích hợp.
* `Selection Sort`: Sắp xếp chọn, quét tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp và hoán vị đúng 1 lần mỗi lượt.
* `Bubble Sort`: Sắp xếp nổi bọt có gắn cờ `swapped` để phát hiện và dừng sớm (Early-Exit) ngay khi mảng đã có thứ tự.
* `QuickSort`: Sắp xếp nhanh phân hoạch Lomuto, kết hợp kỹ thuật chọn Pivot Median-of-Three và khử đệ quy đuôi (Tail-Call Optimization) để khống chế Call Stack tối đa O(log N), chống tràn ngăn xếp.

---

### 2. Cấu trúc mã nguồn
Mã nguồn dự án được tổ chức theo từng tuần:

#### Tuần 1: Cài đặt thuật toán cốt lõi (`4Tuan/Tuan1/`)
* `sorting_algorithms.h`: Khai báo struct `SortStats` và prototype 4 thuật toán sắp xếp.
* `sorting_algorithms.c`: Cài đặt chi tiết Insertion Sort, Selection Sort, Bubble Sort (Early-Exit), QuickSort (Median-of-Three, Tail-Call Optimization).
* `main.c`: Chương trình kiểm thử 4 thuật toán với mảng mẫu $N = 8$.

#### Tuần 2: Bộ sinh kịch bản dữ liệu & Kiểm thử biên (`4Tuan/Tuan2/`)
* `data_generator.h` & `data_generator.c`: Sinh 4 kịch bản phân bố dữ liệu (Ngẫu nhiên, Đã sắp xếp, Nghịch đảo, Gần như có thứ tự - Fisher-Yates) và các hàm tiện ích (`copyArray`, `printArray`, `isSorted`).
* `test_cases.h` & `test_cases.c`: Hiện thực kiểm thử mẫu tính tay được $N = 6$ (`[5, 2, 4, 6, 1, 3]`) và kiểm thử 6 trường hợp biên (mảng rỗng, 1 phần tử, đã có thứ tự, giảm dần, trùng lặp toàn bộ, 2 phần tử nghịch đảo).
* `sorting_algorithms.h` & `sorting_algorithms.c`: Kế thừa mã nguồn thuật toán để kiểm thử độc lập.
* `main.c`: Chương trình thực thi chạy toàn bộ kiểm thử Tuần 2.

---

### 3. Hướng dẫn biên dịch và chạy chương trình
Yêu cầu môi trường: Trình biên dịch GCC (MinGW trên Windows hoặc GCC trên Linux).

#### Chạy kiểm thử Tuần 1:
```bash
cd 4Tuan/Tuan1
gcc -O2 -Wall main.c -o main.exe
.\main.exe
```

#### Chạy kiểm thử Tuần 2:
```bash
cd 4Tuan/Tuan2
gcc -O2 -Wall main.c -o main.exe
.\main.exe
```
