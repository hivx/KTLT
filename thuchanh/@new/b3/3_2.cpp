#include <iostream>
#include <vector>

using namespace std;

// Các bước di chuyển của quân mã
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

int n;                      // Kích thước bàn cờ
int mark[100][100];         // Mảng đánh dấu ô đã đi qua
int X[100 * 100], Y[100 * 100]; // Vị trí các bước đi

// Hàm in kết quả
void print_solution() {
    for (int i = 1; i <= n * n; ++i) {
        printf("(%d %d)\n", X[i], Y[i]);
    }
    exit(0); // Kết thúc chương trình sau khi tìm được một lời giải
}

// Hàm thử nghiệm các bước đi của quân mã
void TRY(int k) {
    for (int i = 0; i < 8; ++i) {
        int xx = X[k - 1] + hx[i]; // Tính tọa độ mới
        int yy = Y[k - 1] + hy[i];
        
        // Kiểm tra bước đi có hợp lệ hay không
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !mark[xx][yy]) {
            X[k] = xx; // Lưu tọa độ bước đi
            Y[k] = yy;
            mark[xx][yy] = 1; // Đánh dấu ô đã đi qua
            
            if (k == n * n) { // Nếu đã đi đủ n * n ô
                print_solution();
            } else {
                TRY(k + 1); // Thử bước đi tiếp theo
            }
            
            // Quay lui
            mark[xx][yy] = 0;
        }
    }
}

int main() {
    cin >> n;

    // Khởi tạo bước đi đầu tiên
    X[1] = 1;
    Y[1] = 1;
    mark[1][1] = 1;

    // Bắt đầu thử nghiệm
    TRY(2);

    // Nếu không tìm được lời giải
    cout << "No solution found!" << endl;
    return 0;
}
