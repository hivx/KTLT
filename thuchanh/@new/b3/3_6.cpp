#include <iostream>
using namespace std;

// Hàm tính ước chung lớn nhất (gcd) bằng thuật toán Euclid
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;  // Nhập hai số a và b

    // Tính và in ra ước chung lớn nhất
    cout << gcd(a, b) << endl;
    cout << gcd(a, b) << endl;

    return 0;
}
