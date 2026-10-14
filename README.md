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
Mã nguồn Tuần 1 được tổ chức tách riêng từng file trong thư mục `4Tuan/Tuan1/`:

* `4Tuan/Tuan1/sorting_algorithms.h`: Khai báo struct `SortStats` (đếm số phép so sánh `comparisons`, số lần hoán vị `moves`, thời gian chạy `time_taken`) và prototype của 4 thuật toán sắp xếp.
* `4Tuan/Tuan1/sorting_algorithms.c`: Cài đặt chi tiết 4 thuật toán sắp xếp cùng các hàm bổ trợ (`swap`, `medianOfThree`, `partition`, `quickSortHelper`).
* `4Tuan/Tuan1/main.c`: Khởi tạo mảng số nguyên mẫu `[29, 10, 14, 37, 13, 25, 45, 12]`, chạy kiểm thử 4 thuật toán và in các thông số thống kê ra console.
* `.gitignore`: Cấu hình loại trừ các file thực thi nhị phân (`*.exe`, `*.o`, `*.zip`) và file tạm khi biên dịch.

---

### 3. Hướng dẫn biên dịch và chạy chương trình
Yêu cầu môi trường: Cài đặt trình biên dịch GCC (MinGW trên Windows hoặc GCC trên Linux).

Thực hiện các lệnh sau trong terminal:

```bash
# Di chuyển vào thư mục mã nguồn Tuần 1
cd 4Tuan/Tuan1

# Biên dịch chương trình với cờ tối ưu -O2 và kiểm tra cảnh báo -Wall
gcc -O2 -Wall main.c -o main.exe

# Chạy chương trình kiểm thử Tuần 1
.\main.exe
```
