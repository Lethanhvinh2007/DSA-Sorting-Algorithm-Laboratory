# ĐỒ ÁN MÔN HỌC: CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT
**Trường:** Đại học Công Nghệ Kỹ thuật TP.HCM (HCMUTE)  
**Đề tài:** Cài đặt và đánh giá thực nghiệm các thuật toán sắp xếp (Insertion, Selection, Bubble, QuickSort)  
**Giảng viên hướng dẫn:** Thầy Huỳnh Xuân Phụng  
**Sinh viên thực hiện:** Lê Thành Vinh - MSSV: 25110075  
**Lớp / Học kỳ:** HK1 2026-2027  

---

## 1. Giới thiệu đề tài
Đề tài thực hiện khảo sát, cài đặt và đánh giá thực nghiệm 4 thuật toán sắp xếp kinh điển:
1. **Insertion Sort (Sắp xếp chèn)**
2. **Selection Sort (Sắp xếp chọn)**
3. **Bubble Sort (Sắp xếp nổi bọt có cờ dừng sớm Early-Exit)**
4. **QuickSort (Sắp xếp nhanh kết hợp Pivot Median-of-Three và khử đệ quy đuôi Tail-Call Optimization)**

Hệ thống theo dõi và đo lường 3 chỉ số chính:
- Số phép so sánh giữa các phần tử (`comparisons`)
- Số phép hoán vị / dịch chuyển ô nhớ (`moves`)
- Thời gian chạy tính bằng mili-giây (`time_taken`)

---

## 2. Kế hoạch thực hiện theo 4 tuần
- **Tuần 1:** Cài đặt hoàn chỉnh 4 thuật toán sắp xếp cốt lõi, tối ưu QuickSort chống tràn stack, kiểm thử tính đúng đắn trên mảng mẫu.
- **Tuần 2:** Xây dựng bộ sinh dữ liệu ngẫu nhiên theo 4 phân phối (Random, Nearly-Sorted, Reverse-Sorted, Many-Duplicates) và kiểm thử 6 trường hợp biên.
- **Tuần 3:** Tiến hành thực nghiệm đo đạc (benchmark) trên các kích thước N = 100, 1.000, 10.000, 100.000; xuất dữ liệu ra file CSV và vẽ biểu đồ phân tích.
- **Tuần 4:** Hoàn thiện giao diện Menu dòng lệnh (CLI), tổng hợp báo cáo nghiệm thu và đóng gói toàn bộ mã nguồn đồ án.

---

## 3. Cấu trúc thư mục dự án
```
Sorting Algorithm Laboratory/
├── 4Tuan/                       # Mã nguồn và báo cáo tiến độ chi tiết từng tuần
│   ├── Tuan1/                   # Cài đặt 4 thuật toán cơ bản & test mẫu
│   ├── Tuan2/                   # Bộ sinh dữ liệu & kiểm thử biên
│   ├── Tuan3/                   # Benchmark đo đạc & xuất CSV
│   └── Tuan4/                   # Menu CLI & báo cáo hoàn thiện
├── src/                         # Mã nguồn tổng hợp hoàn chỉnh của đồ án
├── results/                     # Dữ liệu kết quả thực nghiệm benchmark (CSV, Excel)
├── docs/                        # Báo cáo đồ án chi tiết
└── README.md                    # Tài liệu tổng quan dự án
```

---

## 4. Hướng dẫn biên dịch và chạy chương trình

### Dành cho tiến độ Tuần 1:
Vào thư mục `4Tuan/Tuan1/` và chạy bằng lệnh GCC:
```bash
gcc -O2 -Wall main.c -o main.exe
.\main.exe
```

### Dành cho toàn bộ đồ án (Sau khi tích hợp hoàn chỉnh):
Mở terminal tại thư mục gốc và biên dịch bằng GCC:
```bash
gcc -O2 -Wall src/main.c src/sorting_algorithms.c src/data_generator.c src/benchmark.c src/test_cases.c -o sorting_lab.exe
.\sorting_lab.exe
```
