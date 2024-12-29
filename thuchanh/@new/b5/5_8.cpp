#include <bits/stdc++.h>
using namespace std;

int w, h;
int table[601][601];

void init() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            table[i][j] = i * j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // Sửa lỗi: Thiếu giá trị trả về cho cin.tie()

    cin >> w >> h; // Sửa lỗi: Tránh khai báo lại các biến w và h trong hàm main
    int m;
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }

    // dp
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int minWaste = table[i][j];
            // horizontal cut
            for (int k = 1; k < i; k++) { // Sửa lỗi: Vòng lặp cắt ngang phải dừng trước i
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);
            }
            // vertical cut
            for (int k = 1; k < j; k++) { // Sửa lỗi: Vòng lặp cắt dọc phải dừng trước j
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);
            }
            table[i][j] = minWaste;
        }
    }

    cout << table[h][w] << endl;
    return 0; // Sửa lỗi: Thêm return 0 vào cuối hàm main để chỉ ra rằng chương trình đã kết thúc thành công
}