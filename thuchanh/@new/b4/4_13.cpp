#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countBalancedSubstrings(const string &s) {
    unordered_map<int, ll> balanceCount; // Map lưu tần suất của từng giá trị balance
    balanceCount[0] = 1; // Giá trị ban đầu của balance = 0
    ll balance = 0, count = 0;

    for (char c : s) {
        // Cập nhật giá trị balance
        if (c == '1') {
            balance++;
        } else { // c == '0'
            balance--;
        }

        // Nếu balance đã xuất hiện, cộng số lần xuất hiện trước đó vào kết quả
        if (balanceCount.find(balance) != balanceCount.end()) {
            count += balanceCount[balance];
        }

        // Cập nhật số lần xuất hiện của balance
        balanceCount[balance]++;
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << countBalancedSubstrings(s) << endl;

    return 0;
}
