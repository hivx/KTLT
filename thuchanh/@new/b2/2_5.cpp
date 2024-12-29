// #include <iostream>
// #include <ostream>
// #include <math.h>
// #include <iomanip>

// using namespace std;

// struct sophuc {
//     double real;
//     double imag;
// };

// sophuc operator + (sophuc a, sophuc b) {
//     sophuc tmp;
//     tmp.real = a.real + b.real;
//     tmp.imag = a.imag + b.imag;
//     return tmp;
// }

// sophuc operator - (sophuc a, sophuc b) {
//     sophuc tmp;
//     tmp.real = a.real - b.real;
//     tmp.imag = a.imag - b.imag;
//     return tmp;
// }

// sophuc operator * (sophuc a, sophuc b) {
//     sophuc tmp;
//     tmp.real = a.real*b.real - a.imag*b.imag;
//     tmp.imag = a.real * b.imag + b.real * a.imag;
//     return tmp;
// }

// sophuc operator / (sophuc a, sophuc b) {
// 	sophuc tmp;
//     tmp.real = (a.real*b.real + a.imag*b.imag)/(b.real*b.real + b.imag*b.imag);
//     tmp.imag = (b.real*a.imag - a.real*b.imag)/(b.real*b.real + b.imag*b.imag);
//     return tmp;
// }

// ostream& operator << (ostream& out, const sophuc &a) {
//     out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
//     return out;
// }

// int main() {
//     double real_a, real_b, img_a, img_b;
//     cin >> real_a >> img_a;
//     cin >> real_b >> img_b;

//     sophuc a{real_a, img_a};
//     sophuc b{real_b, img_b};

//     cout << a << " + " << b << " = " << a + b << endl;
//     cout << a << " - " << b << " = " << a - b << endl;
//     cout << a << " * " << b << " = " << a * b << endl;
//     cout << a << " / " << b << " = " << a / b << endl;

//     return 0;
// }

// Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức.

#include<bits/stdc++.h>

using namespace std;

typedef struct {
    double a;
    double b;
} sophuc;

sophuc operator + (sophuc sp1, sophuc sp2) {
    return {sp1.a + sp2.a, sp1.b + sp2.b};
}

sophuc operator - (sophuc sp1, sophuc sp2) {
    return {sp1.a - sp2.a, sp1.b - sp2.b};
}

sophuc operator * (sophuc sp1, sophuc sp2) {
    return {sp1.a*sp2.a - sp1.b*sp2.b, sp1.a*sp2.b + sp1.b*sp2.a};
}

sophuc operator / (sophuc sp1, sophuc sp2) {
    double x1 = sp1.a*sp2.a + sp1.b*sp2.b;
    double x2 = sp1.b*sp2.a - sp1.a*sp2.b;

    double y = sp2.a*sp2.a + sp2.b*sp2.b;
    return {x1 / y, x2 / y};
}

ostream& operator << (ostream& out, const sophuc& a) {
    out << '(' << fixed << setprecision(2) << a.a << (a.b >= 0 ? " + " : " - ") << fixed << setprecision(2) << fabs(a.b) << 'i' << ')';
    return out;
}

int main() {
    sophuc sp1, sp2;
    cin >> sp1.a >> sp1.b;
    cin >> sp2.a >> sp2.b;

    cout << sp1 << " + " << sp2 << " = " << sp1 + sp2 <<endl;
    cout << sp1 << " - " << sp2 << " = " << sp1 - sp2 <<endl;
    cout << sp1 << " * " << sp2 << " = " << sp1 * sp2 <<endl;
    cout << sp1 << " / " << sp2 << " = " << sp1 / sp2 <<endl;

    return 0;
}