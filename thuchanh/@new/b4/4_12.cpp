#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Hàm tìm diện tích hình chữ nhật lớn nhất
ll largestRectangleArea(vector<ll> &heights) {
    stack<int> st; // Stack lưu chỉ số cột
    ll max_area = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i) {
        // Khi cột hiện tại thấp hơn cột trên đỉnh Stack
        while (!st.empty() && heights[st.top()] > heights[i]) {
            ll h = heights[st.top()];
            st.pop();
            ll width = st.empty() ? i : (i - st.top() - 1);
            max_area = max(max_area, h * width);
        }
        st.push(i);
    }

    // Xử lý các cột còn lại trong Stack
    while (!st.empty()) {
        ll h = heights[st.top()];
        st.pop();
        ll width = st.empty() ? n : (n - st.top() - 1);
        max_area = max(max_area, h * width);
    }

    return max_area;
}

int main() {
    // Tăng tốc độ nhập xuất
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    cout << largestRectangleArea(heights) << "\n";

    return 0;
}
