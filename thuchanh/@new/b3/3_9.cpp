#include <bits/stdc++.h>
using namespace std;

struct State {
    int i;               // Vị trí hiện tại trong chuỗi
    int currentLength;   // Độ dài chuỗi làm việc liên tiếp hiện tại
    int lastBit;         // Bit cuối cùng (0: nghỉ, 1: làm việc)
    string schedule;     // Chuỗi lịch làm việc
    State(int _i, int _currentLength, int _lastBit, string _schedule) 
        : i(_i), currentLength(_currentLength), lastBit(_lastBit), schedule(_schedule) {}
};

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    queue<State> q;
    vector<string> results;

    // Khởi tạo trạng thái ban đầu
    q.emplace(0, 0, -1, "");  // -1: chưa quyết định (trạng thái khởi đầu)

    while (!q.empty()) {
        State top = q.front();
        q.pop();

        // Nếu đã hoàn thành chuỗi lịch làm việc
        if (top.i == N) {
            results.push_back(top.schedule);
            continue;
        }

        // Thử đặt nghỉ (0)
        if (top.lastBit != 0) { // Không cho phép hai ngày nghỉ liên tiếp
            q.emplace(top.i + 1, 0, 0, top.schedule + "0");
        }

        // Thử đặt làm việc (1)
        if (top.currentLength + 1 <= K2) { // Không vượt quá K2 ngày làm việc liên tiếp
            q.emplace(top.i + 1, top.currentLength + 1, 1, top.schedule + "1");
        }
    }

    // Lọc kết quả theo điều kiện độ dài chuỗi làm việc liên tiếp trong [K1, K2]
    for (const string &schedule : results) {
        bool isValid = true;
        int workLength = 0;

        for (char c : schedule) {
            if (c == '1') {
                workLength++;
            } else {
                if (workLength > 0 && (workLength < K1 || workLength > K2)) {
                    isValid = false;
                    break;
                }
                workLength = 0;
            }
        }
        if (workLength > 0 && (workLength < K1 || workLength > K2)) {
            isValid = false;
        }

        if (isValid) {
            cout << schedule << endl;
        }
    }

    return 0;
}
