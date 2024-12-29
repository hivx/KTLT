#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x, y, z;
} block;

int n;
block a[300]; // Khởi tạo mảng đủ lớn để chứa tất cả các khối
int maxh[300]; // Khởi tạo mảng đủ lớn để chứa chiều cao tối đa

void input() {
    cin >> n;
    if (n == 0) exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++) { // Sửa điều kiện vòng lặp
        cin >> x >> y >> z;
        a[3 * i - 3].x = x;
        a[3 * i - 3].y = y;
        a[3 * i - 3].z = z;
        a[3 * i - 2].x = y;
        a[3 * i - 2].y = z;
        a[3 * i - 2].z = x;
        a[3 * i - 1].x = z;
        a[3 * i - 1].y = x;
        a[3 * i - 1].z = y;
    }
}

int dp(int i) { // Tìm chiều cao của tòa tháp với đỉnh là viên i
    if (maxh[i] != 0) return maxh[i];
    maxh[i] = a[i].z;
    for (int j = 0; j < 3 * n; j++) { // Sửa điều kiện vòng lặp
        if ((a[i].x < a[j].x && a[i].y < a[j].y) || 
            (a[i].x < a[j].y && a[i].y < a[j].x)) {
            maxh[i] = max(maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main() {
    int cnt = 1;
    while (true) {
        int res = 0;
        input();
        memset(maxh, 0, sizeof(maxh)); // Khởi tạo mảng maxh
        for (int i = 0; i < 3 * n; i++) { // Sửa điều kiện vòng lặp
            res = max(res, dp(i));
        }
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}