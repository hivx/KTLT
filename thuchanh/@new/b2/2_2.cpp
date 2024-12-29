// #include <stdio.h>

// void rotate(int &x, int &y, int &z) {
//     int temp = x;
//         x = y;
//         y = z;
//         z = temp;
// }

// int main() {
//     int x, y, z;
//     scanf("%d %d %d", &x, &y, &z);
//     printf("Before: %d, %d, %d\n", x, y, z);
//     rotate(x, y, z);
//     printf("After: %d, %d, %d\n", x, y, z);

//     return 0;
// }

//Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, 
//các biến a, b, c tương ứng nhận các giá trị mới b, c, a.

#include<bits/stdc++.h>

using namespace std;

//void rotate(int& a, int& b, int& c)
void rotate(int* a, int* b, int* c) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = *c;
    *c = tmp;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << "Cac so ban dau la: " << a << " " << b << " " << c << endl;

    rotate(&a, &b, &c);
    cout << "Cac sau hoan doi la: " << a << " " << b << " " << c << endl;

    return 0;
}
