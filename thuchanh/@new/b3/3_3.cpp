#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;                           // Số lượng thành phố
vector<vector<int>> c;           // Ma trận chi phí
vector<bool> visited;            // Mảng đánh dấu các thành phố đã đi qua
int min_cost = INT_MAX;          // Chi phí nhỏ nhất
int current_cost = 0;            // Chi phí tạm thời
vector<int> path;                // Đường đi tạm thời

// Hàm quay lui để thử tất cả các cách đi
void TRY(int city, int count) {
    if (count == n) { // Đã đi qua tất cả các thành phố
        if (c[city][0] != 0) { // Kiểm tra chi phí quay về thành phố 1
            min_cost = min(min_cost, current_cost + c[city][0]);
        }
        return;
    }

    for (int next_city = 0; next_city < n; ++next_city) {
        if (!visited[next_city] && c[city][next_city] != 0) { // Nếu thành phố chưa được thăm và có đường đi
            visited[next_city] = true; // Đánh dấu thành phố đã thăm
            current_cost += c[city][next_city]; // Cộng chi phí di chuyển

            if (current_cost < min_cost) { // Chỉ tiếp tục nếu chi phí tạm thời < min_cost
                TRY(next_city, count + 1);
            }

            // Quay lui
            visited[next_city] = false;
            current_cost -= c[city][next_city];
        }
    }
}

int main() {
    cin >> n;

    // Khởi tạo ma trận chi phí
    c.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    // Bắt đầu từ thành phố 1
    visited[0] = true;
    TRY(0, 1);

    // Xuất kết quả
    cout << min_cost << endl;

    return 0;
}
