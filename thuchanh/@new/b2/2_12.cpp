#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> list;
    int key, value;

    // Đọc dữ liệu đầu vào
    while (cin >> key >> value) {
        list.push_back(make_pair(key, value));
    }

    // Sắp xếp giảm dần theo value, nếu value giống nhau thì sắp xếp theo key giảm dần
    sort(list.begin(), list.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;  // Nếu value bằng nhau, sắp xếp theo key giảm dần
        }
        return a.second > b.second;  // Sắp xếp theo value giảm dần
    });

    // In kết quả đã sắp xếp
    for (const auto& p : list) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
