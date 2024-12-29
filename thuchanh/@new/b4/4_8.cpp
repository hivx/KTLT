#include <iostream>
#include <map>
#include <algorithm> // Để sử dụng hàm std::max và std::min

using namespace std;

// Hợp mờ của hai tập hợp
template <class T>
std::map<T, double> fuzzy_set_union(const std::map<T, double> &a, const std::map<T, double> &b) {
    std::map<T, double> c = a;
    for (const auto &e : b) {
        if (c.count(e.first)) {
            c[e.first] = max(c[e.first], e.second);
        } else {
            c.insert(e);
        }
    }
    return c;
}

// Giao mờ của hai tập hợp
template <class T>
std::map<T, double> fuzzy_set_intersection(const std::map<T, double> &a, const std::map<T, double> &b) {
    std::map<T, double> c;
    for (const auto &x : a) {
        const auto it = b.find(x.first);
        if (it != b.end()) {
            c[x.first] = min(x.second, it->second);
        }
    }
    return c;
}

// In tập hợp mờ
template <class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}" << endl;
}

int main() {
    // Khởi tạo các tập hợp mờ
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1.0}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1.0}};

    // In các tập hợp ban đầu
    std::cout << "A = ";
    print_fuzzy_set(a);

    std::cout << "B = ";
    print_fuzzy_set(b);

    // Tính hợp mờ và giao mờ
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);

    // In kết quả
    std::cout << "Union: ";
    print_fuzzy_set(c);

    std::cout << "Intersection: ";
    print_fuzzy_set(d);

    return 0;
}
