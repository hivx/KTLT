// #include <stdio.h>

// int cube(int x) {

//     int n;
//     return n=x*x*x;
// }

// double cube(double x) {
// 	double f;
//     return f=x*x*x;
// }
// int main() {
//     int n;
//     double f;
//     scanf("%d %lf", &n, &f);

//     printf("Int: %d\n", cube(n));
//     printf("Double: %.2lf\n", cube(f));

//     return 0;
// }

//Viết các hàm tính lập phương của số nguyên và số thực.

#include<bits/stdc++.h>

using namespace std;

// void cube(int* n, double* f) {
//     *n = *n * *n *n;
//     *f = *f * *f *f;
// }

// int cube(int* n) {
//     return *n = *n * *n * *n;
// }

int cube(int x) {
    return x = x * x * x;
}

double cube(double x) {
    return x = x * x * x;
}

int main() {
    int n; cin >> n;

    double f; cin >> f;

    // cube(&n, &f);

    cout <<cube(n) << endl;

    cout << fixed << setprecision(2) << cube(f) << endl;

    return 0;
}