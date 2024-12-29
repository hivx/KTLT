#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while (n--) {
        int k, t;
        cin >> k >> t;
        // đưa điều kiện ra ngoài vòng lặp
        if (t == 1) { 
            while (k--) {
                int a;
                cin >> a;
                sum += a;
            }
        } else {
            while (k--) {
                int a;
                cin >> a;
                sum -= a;
            }
        }
        // đưa phép tính ra ngoài vòng lặp
        ans = max(ans, -sum); 
    }
    cout << ans;
    return 0;
}