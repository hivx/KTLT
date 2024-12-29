#include <bits/stdc++.h>
using namespace std;

char cal(double a) {
    //dùng else if để giảm số lần kiểm tra điều kiện
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    else return 'A';
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(5, 0); // Mảng lưu trữ số lượng các hạng: A, B, C, D, F
    while (n--) {
        double a;
        cin >> a;
        switch (cal(a)) {
            case 'A': ++grades[0]; break;
            case 'B': ++grades[1]; break;
            case 'C': ++grades[2]; break;
            case 'D': ++grades[3]; break;
            case 'F': ++grades[4]; break;
        }
    }
    cout << grades[0] << " " << grades[1] << " " << grades[2] << " " << grades[3] << " " << grades[4];
    return 0;
}