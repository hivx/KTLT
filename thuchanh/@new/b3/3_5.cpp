#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Mảng 2 chiều để lưu hệ số tổ hợp C(n, k)
    vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));

    // Khởi tạo mảng Pascal
    for (int i = 0; i <= n; ++i) {
        C[i][0] = C[i][i] = 1; // C(n, 0) và C(n, n) đều bằng 1
    }

    // Tính các giá trị còn lại trong mảng Pascal
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    // In kết quả theo định dạng yêu cầu
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
        for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
