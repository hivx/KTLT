#include <iostream>
#include <vector>
#include <algorithm>

// In các phần tử của vector
void print_vector(const std::vector<int> &a) {
    for (int v : a)
        std::cout << v << ' ';
    std::cout << std::endl;
}

// Xóa các phần tử chẵn trong vector
void delete_even(std::vector<int> &a) {
    a.erase(std::remove_if(a.begin(), a.end(), [] (int x) { return x % 2 == 0; }), a.end());
}

// Sắp xếp vector theo thứ tự giảm dần
void sort_decrease(std::vector<int> &a) {
    std::sort(a.rbegin(), a.rend());
}

// Trộn 2 vector và trả về vector mới, sắp xếp giảm dần
std::vector<int> merge_vectors(const std::vector<int> &a, const std::vector<int> &b) {
    std::vector<int> c;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c), std::greater<int>());
    return c;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;

    // Nhập số phần tử của vector a và b
    std::cin >> m >> n;

    // Nhập các phần tử của vector a
    for (int i = 0; i < m; i++) {
        std::cin >> u;
        a.push_back(u);
    }

    // Nhập các phần tử của vector b
    for (int i = 0; i < n; i++) {
        std::cin >> u;
        b.push_back(u);
    }

    // Xóa phần tử chẵn trong a và b
    delete_even(a);
    std::cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    std::cout << "Odd elements of b: ";
    print_vector(b);

    // Sắp xếp giảm dần vector a và b
    sort_decrease(a);
    std::cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    std::cout << "Decreasingly sorted b: ";
    print_vector(b);

    // Trộn a và b thành c
    std::vector<int> c = merge_vectors(a, b);
    std::cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
