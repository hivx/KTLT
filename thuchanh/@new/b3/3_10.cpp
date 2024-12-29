#include <bits/stdc++.h>
using namespace std;

// Hàm quay lui để liệt kê các xâu nhị phân có độ dài N và đúng H bit 1
void generateStrings(int idx, int H, int N, string &current, vector<string> &result) {
    if (idx == N) {
        if (H == 0) { // Nếu đủ H bit 1
            result.push_back(current);
        }
        return;
    }

    // Gắn '0' vào vị trí idx
    current[idx] = '0';
    generateStrings(idx + 1, H, N, current, result);

    // Gắn '1' vào vị trí idx (nếu vẫn còn cần thêm bit 1)
    if (H > 0) {
        current[idx] = '1';
        generateStrings(idx + 1, H - 1, N, current, result);
    }
}

int main() {
    int T; // Số testcase
    cin >> T;
    while (T--) {
        int N, H;
        cin >> N >> H;

        vector<string> result;
        string current(N, '0'); // Xâu hiện tại độ dài N toàn '0'

        // Gọi hàm quay lui để sinh các xâu nhị phân
        generateStrings(0, H, N, current, result);

        // In kết quả
        for (const string &s : result) {
            cout << s << endl;
        }

        // In dòng trống giữa các testcase
        if (T > 0) {
            cout << endl;
        }
    }
    return 0;
}
