#include <bits/stdc++.h>
using namespace std;

int m, n, Smin = INT_MAX; // Sử dụng INT_MAX để khởi tạo giá trị lớn nhất
long long S = 0;
int cmin = INT_MAX; // Sử dụng INT_MAX để khởi tạo giá trị lớn nhất
int x[100];
int c[100][100];
vector<int> flag(100, false);

void TRY(int k) {
    for (int i = 2; i <= n; i++) {
        if (!flag[i] && c[x[k - 1]][i] != -1) {
            flag[i] = true;
            x[k] = i;
            S += c[x[k - 1]][i];
            if (k == n) {
                if (S + c[i][1] < Smin && c[i][1] != -1)
                    Smin = S + c[i][1];
            } else if (S + cmin * (n - k + 1) < Smin) {
                TRY(k + 1);
            }
            flag[i] = false;
            S -= c[x[k - 1]][i];
        }
    }
}

int main() {
    int a, b, cost;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = (i == j) ? 0 : -1; // Khởi tạo ma trận chi phí

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cost;
        c[a][b] = cost;
        c[b][a] = cost; // Nếu đồ thị vô hướng
        if (cost < cmin)
            cmin = cost;
    }

    x[1] = 1;
    flag[1] = true;
    TRY(2);
    cout << Smin;
    return 0;
}