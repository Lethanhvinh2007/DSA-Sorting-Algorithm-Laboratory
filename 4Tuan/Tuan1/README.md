# BÁO CÁO TIẾN ĐỘ TUẦN 1: CÀI ĐẶT 4 THUẬT TOÁN SẮP XẾP CỐT LÕI
- **Trường:** Đại học Công Nghệ Kỹ thuật TP.HCM (HCMUTE)
- **Môn học:** Cấu trúc dữ liệu và Giải thuật
- **Giảng viên hướng dẫn:** Thầy Huỳnh Xuân Phụng
- **Sinh viên thực hiện:** Lê Thành Vinh - MSSV: 25110075
- **Tiến độ:** Tuần 1 / 4 tuần

---

## 1. Mục tiêu công việc Tuần 1
Trong tuần đầu tiên, đề tài tập trung vào việc hiện thực hóa và kiểm thử tính đúng đắn của 4 thuật toán sắp xếp cơ bản và nâng cao trên mảng số nguyên bằng ngôn ngữ C:
1. **Insertion Sort (Sắp xếp chèn):** Duyệt mảng con và dịch chuyển các phần tử lớn hơn khóa sang phải (shift).
2. **Selection Sort (Sắp xếp chọn):** Quét tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp và hoán vị đúng 1 lần mỗi lượt.
3. **Bubble Sort Early-Exit:** Sắp xếp nổi bọt có gắn cờ `swapped` để dừng sớm khi mảng đã có thứ tự.
4. **QuickSort Lomuto:** Kết hợp kỹ thuật chọn Pivot Median-of-Three và khử đệ quy đuôi (Tail-Call Optimization).

Đồng thời, thiết kế cấu trúc `SortStats` để theo dõi chính xác:
- `comparisons`: Số phép so sánh giữa các phần tử.
- `moves`: Số lần hoán vị hoặc dịch chuyển phần tử (swap & shift).
- `time_taken`: Thời gian thực thi (mili-giây ms).

---

## 2. Kỹ thuật cài đặt & Tối ưu hóa
- **Chiến lược Median-of-Three:** Chọn phần tử trung vị của 3 vị trí (`low`, `mid`, `high`) làm Pivot để hạn chế tối đa nguy cơ suy biến về O(N^2) khi mảng đã có thứ tự sẵn.
- **Khử đệ quy đuôi (Tail-Call Optimization):** Luôn gọi đệ quy trên nửa mảng nhỏ hơn trước, còn nửa mảng lớn hơn được xử lý bằng vòng lặp `while`. Kỹ thuật này giúp khống chế độ sâu Call Stack tối đa là O(log N), tránh tràn bộ nhớ stack khi kích thước dữ liệu lớn.

---

## 3. Cấu trúc thư mục Tuần 1
- `sorting_algorithms.h`: Khai báo struct `SortStats` và prototype của 4 thuật toán sắp xếp.
- `sorting_algorithms.c`: Cài đặt chi tiết 4 thuật toán sắp xếp và các hàm bổ trợ (`swap`, `medianOfThree`, `partition`, `quickSortHelper`).
- `main.c`: Chương trình kiểm thử 4 thuật toán trên mảng mẫu `[29, 10, 14, 37, 13, 25, 45, 12]`.
- `README.md`: Báo cáo tiến độ và hướng dẫn chạy kiểm thử Tuần 1.

---

## 4. Hướng dẫn biên dịch và chạy thử
Biên dịch và chạy trực tiếp bằng trình biên dịch GCC:
```bash
gcc -O2 -Wall main.c -o main.exe
.\main.exe
```

---

## 5. Kết quả kiểm thử
- Biên dịch bằng `gcc -O2 -Wall` đạt 0 lỗi, 0 cảnh báo.
- Chương trình chạy kiểm tra trên mảng 8 phần tử: `[29, 10, 14, 37, 13, 25, 45, 12]`.
- Kết quả in ra console:
  Mảng sau khi sắp xếp của cả 4 thuật toán đều đạt thứ tự tăng dần chính xác:
  `[10, 12, 13, 14, 25, 29, 37, 45]`
