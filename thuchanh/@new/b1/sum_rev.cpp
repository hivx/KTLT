#include <iostream>
#include <vector>

using namespace std;

int count_subarrays_with_sum_greater_than_T(const vector<int>& revenues, int T) {
    int n = revenues.size();
    vector<int> prefix_sum(n + 1, 0);

    // Tính toán prefix_sum - tong cua cac so lien tiep tu a[0] -> a[4]
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + revenues[i];
    }

    int count = 0;

    // Kiểm tra tất cả các dãy con liên tiếp
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            //lay tong cac so tu a[0] -> a[4] tru di 1 a[i] ta se duoc tong cca day con
            if (prefix_sum[j] - prefix_sum[i] > T) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int n, T;
    cout << "Nhap so ngay: ";
    cin >> n;
    vector<int> revenues(n);

    cout << "Nhap doanh thu cua tung ngay: ";
    for (int i = 0; i < n; ++i) {
        cin >> revenues[i];
    }

    cout << "Nhap gia tri T: ";
    cin >> T;

    int result = count_subarrays_with_sum_greater_than_T(revenues, T);
    cout << "So cach chon ngay lien tiep sao cho tong doanh thu lon hon " << T << " la: " << result << endl;

    return 0;
}