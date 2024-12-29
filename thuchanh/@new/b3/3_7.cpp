#include <bits/stdc++.h>

using namespace std;

struct state {
    int i, j, old_L;

    // Constructor
    state(int i = 0, int j = 0, int _L = 0) : i(i), j(j), old_L(_L) {}
};

int main() {
    int n, k;
    cin >> n >> k;

    int x[n + 1]; // Mảng lưu xâu nhị phân

    stack<state> s;

    // Số bit 1 liên tiếp
    int L = 0;

    s.push(state(1, 0, 0));

    while (!s.empty()) {
        state &top = s.top();

        // Nếu đã có xâu nhị phân đầy đủ
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " ";  // In ra xâu nhị phân
            cout << endl;
            s.pop();
            continue;
        }

        // Quay lui nếu cần thiết
        if (top.j > 0)
            L = top.old_L;

        // Thăm các nhánh con của cây tìm kiếm
        if (top.j > 1) {
            s.pop();
            continue;
        }

        // Nếu thêm bit 1 hợp lệ (không vượt quá k bit 1 liên tiếp)
        if (L + 1 < k || top.j == 0) {
            x[top.i] = top.j;
            top.old_L = L;
            L = (top.j ? L + 1 : 0);
            s.push(state(top.i + 1, 0, L));  // Tiến sang phần tử tiếp theo
        }

        ++top.j;
    }

    return 0;
}
