// #include <iostream>
// using namespace std;

// //# vi?t hàm arr_sum
// template <class h>
// h arr_sum(h* a, int x, h* b, int y){
//     h sum=0;
//     for( int i=0; i<x || i<y; i++){
//         if(i<x) sum+=a[i];
//         if(i<y) sum+=b[i];
//     }
//     return sum;
// }
// int main() {
//     int val;
//     cin >> val;

//     {
//         int a[] = {3, 2, 0, val};
//         int b[] = {5, 6, 1, 2, 7};
//         cout << arr_sum(a, 4, b, 5) << endl;
//     }
//     {
//         double a[] = {3.0, 2, 0, val * 1.0};
//         double b[] = {5, 6.1, 1, 2.3, 7};
//         cout << arr_sum(a, 4, b, 5) << endl;
//     }

//     return 0;
// }
// Viết hàm tính tổng các phần tử trong hai mảng.Yêu cầu sử dụng 
//function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.

#include <bits/stdc++.h>

using namespace std;

template <typename h>
h arr_sum(h* a, int aS, h* b, int bS) {
    h sum = 0;
    for (int i = 0; i < aS || i < bS; i++) {
        if(i < aS) {sum += a[i];}
        if(i < bS) {sum += b[i];}
    }
    return sum;
}

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << fixed <<setprecision(2) << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}