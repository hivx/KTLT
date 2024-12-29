#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using Point = std::pair<double, double>;

// Hàm tính diện tích tam giác từ 3 điểm
double area(Point a, Point b, Point c) {
    return fabs(
        a.first * (b.second - c.second) +
        b.first * (c.second - a.second) +
        c.first * (a.second - b.second)
    ) / 2.0;
}

int main() {
    std::cout << std::setprecision(2) << std::fixed;

    // Tính diện tích tam giác từ 3 điểm
    std::cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << std::endl;

    return 0;
}
