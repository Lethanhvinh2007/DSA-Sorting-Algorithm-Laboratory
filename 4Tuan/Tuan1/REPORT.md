# BÁO CÁO TIẾN ĐỘ TUẦN 1: CÀI ĐẶT 4 THUẬT TOÁN SẮP XẾP CỐT LÕI
**Trường:** Đại học Công Nghệ Kỹ thuật TP.HCM (HCMUTE)  
**Đề tài:** Sorting Algorithm Laboratory: Insertion, Selection, Bubble, Quicksort  
**Giảng viên hướng dẫn:** Thầy Huỳnh Xuân Phụng  
**Sinh viên thực hiện:** Lê Thanh Vinh - MSSV: 25110075  
**Giai đoạn:** Tuần 1 / 4 tuần

---

## 1. Mục tiêu công việc trong Tuần 1
- Cài đặt hoàn chỉnh 4 thuật toán sắp xếp trên mảng số nguyên bằng ngôn ngữ C chuẩn:
  1. **Insertion Sort (Sắp xếp chèn):** Duyệt mảng con và trượt phần tử (shift).
  2. **Selection Sort (Sắp xếp chọn):** Quét tìm phần tử nhỏ nhất và hoán vị đúng 1 lần mỗi lượt.
  3. **Bubble Sort Early-Exit:** Sắp xếp nổi bọt có gắn cờ dừng sớm khi mảng đã có thứ tự.
  4. **QuickSort (Lomuto + Median-of-Three + Khử đệ quy đuôi):** Sắp xếp nhanh an toàn, khống chế độ sâu ngăn xếp.
- Thiết kế struct `SortStats` đếm chính xác: số phép so sánh (`comparisons`), số hoán vị/dời ô (`moves`), thời gian thực thi (`time_taken`).

---

## 2. Kỹ thuật cài đặt & Tối ưu hóa
- **Chiến lược Median-of-Three:** Chọn phần tử trung vị của 3 vị trí (low, mid, high) làm Pivot để hạn chế tối đa nguy cơ suy biến về O(N^2) khi mảng đã có thứ tự sẵn.
- **Khử đệ quy đuôi (Tail-Call Optimization):** Luôn gọi đệ quy trên nửa mảng nhỏ hơn trước, còn nửa mảng lớn hơn được xử lý bằng vòng lặp while. Kỹ thuật này giúp khống chế độ sâu Call Stack tối đa là O(log N), tránh tràn bộ nhớ stack khi kích thước dữ liệu lớn.

---

## 3. Kết quả nghiệm thu Tuần 1
- Biên dịch với `gcc -O2 -Wall` đạt **0 cảnh báo (warning)**.
- Chạy kiểm thử mẫu với mảng 8 phần tử: `[29, 10, 14, 37, 13, 25, 45, 12]`.
- Cả 4 thuật toán đều cho ra kết quả sắp xếp tăng dần chính xác: `[10, 12, 13, 14, 25, 29, 37, 45]`.
