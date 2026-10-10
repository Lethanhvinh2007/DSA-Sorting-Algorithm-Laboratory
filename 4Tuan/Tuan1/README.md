# BÁO CÁO TIẾN ĐỘ TUẦN 1: CÀI ĐẶT 4 THUẬT TOÁN SẮP XẾP CỐT LÕI
- **Trường:** Đại học Công Nghệ Kỹ thuật TP.HCM (HCMUTE)
- **Môn học:** Cấu trúc dữ liệu và Giải thuật
- **Giảng viên hướng dẫn:** Thầy Huỳnh Xuân Phụng
- **Sinh viên thực hiện:** Lê Thành Vinh - MSSV: 25110075
- **Tiến độ:** Tuần 1 / 4 tuần

---

## 1. Mục tiêu công việc Tuần 1
Trong tuần đầu tiên, đề tài tập trung vào việc hiện thực hóa và kiểm thử tính đúng đắn của 4 thuật toán sắp xếp cơ bản và nâng cao trên mảng số nguyên:
1. **Insertion Sort (Sắp xếp chèn):** Duyệt mảng con và dịch chuyển các phần tử lớn hơn khóa sang phải.
2. **Selection Sort (Sắp xếp chọn):** Quét tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp và hoán vị đúng 1 lần mỗi lượt.
3. **Bubble Sort Early-Exit:** Sắp xếp nổi bọt có gắn cờ `swapped` để dừng sớm khi mảng đã có thứ tự.
4. **QuickSort (Lomuto + Median-of-Three + Khử đệ quy đuôi):** Sắp xếp nhanh an toàn, chọn pivot trung vị của 3 phần tử (low, mid, high) và đệ quy nửa nhỏ hơn trước để khống chế call stack tối đa O(log N).

Đồng thời, thiết kế cấu trúc `SortStats` để theo dõi chính xác:
- `comparisons`: Số phép so sánh giữa các phần tử.
- `moves`: Số lần hoán vị hoặc dịch chuyển phần tử (swap & shift).
- `time_taken`: Thời gian thực thi (mili-giây ms).

---

## 2. Cấu trúc thư mục Tuần 1
- `sorting_algorithms.h`: Khai báo struct `SortStats` và prototype của 4 thuật toán sắp xếp.
- `sorting_algorithms.c`: Cài đặt chi tiết 4 thuật toán sắp xếp và các hàm bổ trợ (`swap`, `medianOfThree`, `partition`, `quickSortHelper`).
- `main.c`: Chương trình kiểm thử 4 thuật toán trên mảng mẫu `[29, 10, 14, 37, 13, 25, 45, 12]`.
- `REPORT.md`: Báo cáo tóm tắt kết quả nghiệm thu của Tuần 1.

---

## 3. Hướng dẫn biên dịch và chạy thử
Biên dịch và chạy trực tiếp bằng trình biên dịch GCC:
```bash
gcc -O2 -Wall main.c -o main.exe
.\main.exe
```

---

## 4. Kết quả kiểm thử
Chương trình chạy kiểm tra trên mảng 8 phần tử:
`[29, 10, 14, 37, 13, 25, 45, 12]`

Kết quả in ra console:
- Mảng sau khi sắp xếp của cả 4 thuật toán đều đạt thứ tự tăng dần chính xác:
  `[10, 12, 13, 14, 25, 29, 37, 45]`
- Biên dịch với cờ `-O2 -Wall` đạt 0 lỗi và 0 cảnh báo.
