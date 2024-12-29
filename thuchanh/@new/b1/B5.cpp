// Bài tập 5
// Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double.
// Nếu mảng rỗng hãy trả về NULL.

#include<stdio.h>

double* maximum(double* a, int size) {
    if (a == NULL || size <= 0) return NULL;

    double *max = a;

    for (int i = 1; i < size; ++i) {
        if (a[i] > *max) {
            max = &a[i];
        }
    }
    
    return max;
}

int main() {
    int n;
    scanf("%d", &n);

    double a[n];
    for (int i = 0; i < n; ++i) {scanf("%lf", &a[i]);}

    double* result = maximum(a, n);

    printf("%p", result);
    delete[] a;
    
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// double* ptrmax(const double* a, int n) {
//     if (a==NULL || n<=0) return NULL;

//     double* max = (double*)&a[0];
    
//     for(int i = 0; i < n; i++) {
//         if(*max < a[i]) {
//             max = (double*)&a[i];
//         }
//     }

//     return max;
// }

// int main() {
//     int n;
//     cin >> n;
    
//     // double a[n];
//     // vector<double> a(n); ko cap phat dong nua
//     double* a = new double[n];
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
    
//     //check dia chi cua cac phan tu
//     for (int i=0; i<n;i++) {
//         cout << (void*)&a[i] <<endl;
//     }

//     double* result = ptrmax(a, n);
//     cout << endl << result << endl;

//     //giai phong bo nho
//     delete[] a;

//     return 0;
// }