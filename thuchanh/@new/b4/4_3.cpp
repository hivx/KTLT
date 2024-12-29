#include <iostream>
#include <cmath>
#include <iomanip>
#include <tuple>  // Để sử dụng std::tuple

using namespace std;

// Định nghĩa kiểu Vector
using Vector = std::tuple<double, double, double>;

// Hàm tính tích có hướng của hai vector
Vector cross_product(Vector a, Vector b) {
    return Vector(
        std::get<1>(a) * std::get<2>(b) - std::get<2>(a) * std::get<1>(b), // c_x
        std::get<2>(a) * std::get<0>(b) - std::get<0>(a) * std::get<2>(b), // c_y
        std::get<0>(a) * std::get<1>(b) - std::get<1>(a) * std::get<0>(b)  // c_z
    );
}

int main() {
    // Định dạng số thập phân
    cout << setprecision(2) << fixed;

    // Hai vector cần tính
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};

    // Tính tích có hướng
    Vector c = cross_product(a, b);

    // In kết quả
    cout << std::get<0>(c) << ' ' << std::get<1>(c) << ' ' << std::get<2>(c) << endl;

    return 0;
}
