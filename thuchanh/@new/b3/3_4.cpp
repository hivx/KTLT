#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Mảng dp lưu độ dài LIS kết thúc tại mỗi phần tử
    vector<int> dp(n, 1);
    // Mảng parent lưu chỉ số phần tử trước đó trong LIS
    vector<int> parent(n, -1);

    int max_length = 1;  // Độ dài LIS dài nhất
    int last_index = 0;  // Chỉ số phần tử cuối cùng trong LIS dài nhất

    // Tính toán LIS
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;  // Lưu chỉ số phần tử trước đó trong dãy LIS
            }
        }
        
        // Cập nhật độ dài LIS và chỉ số phần tử cuối cùng nếu tìm thấy LIS dài hơn
        if (dp[i] > max_length) {
            max_length = dp[i];
            last_index = i;
        }
    }

    // Phục hồi dãy con tăng dài nhất
    vector<int> lis;
    while (last_index != -1) {
        lis.push_back(a[last_index]);
        last_index = parent[last_index];
    }

    // In kết quả
    cout << max_length << endl;
    for (int i = lis.size() - 1; i >= 0; --i) {
        cout << lis[i] << " ";
    }
    cout << endl;

    return 0;
}
