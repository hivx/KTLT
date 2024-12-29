#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool found = false;
    while (n--) {
        int a;
        cin >> a;
        // Điều kiện kiểm tra năm nhuận
        if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) {
            found = true;
            break; // Thoát khỏi vòng lặp khi tìm thấy năm nhuận
        }
    }
    cout << (found ? "Yes" : "No") << endl; // In kết quả dùng toán tử 3 ngôi
    return 0;
}