// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>

// using namespace std;

// // Hàm so sánh: sắp xếp vector con theo tổng phần tử giảm dần
// bool compare(const vector<int>& v1, const vector<int>& v2) {
//     int sum1 = accumulate(v1.begin(), v1.end(), 0);
//     int sum2 = accumulate(v2.begin(), v2.end(), 0);
//     return sum1 > sum2; // Tổng lớn hơn sẽ đứng trước
// }

// int main() {
//     int val1, val2;
//     cin >> val1 >> val2;
//     vector<vector<int>> a = {
//         {1, 3, 7},
//         {2, 3, 4, val1},
//         {9, 8, 15},
//         {10, val2},
//     };

//     // Sắp xếp các vector con theo tổng phần tử giảm dần
//     sort(a.begin(), a.end(), compare);

//     // In kết quả
//     for (const auto& v : a) {
//         for (int it : v) {
//             cout << it << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Viết hàm so sánh cho thuật toán sắp xếp.

#include<bits/stdc++.h>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    int sum1 = accumulate(a.begin(), a.end(), 0);
    int sum2 = accumulate(b.begin(), b.end(), 0);
    return sum1 > sum2;
}

int main() {
    int val1, val2;
    cin >> val1 >> val2;

    vector<vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    sort(a.begin(), a.end(), compare);

    for (const auto& v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }

    return 0;
}
