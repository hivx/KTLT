#include <iostream>
using namespace std;
int main() {
    int a = 6, b = 12;
    int *p = &a, *q = &b;
    ++a = ~a + ~~b;
    p--;
    *p-- = a + ~2;
    cout << a << ", " << b;
}
