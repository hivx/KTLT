// #include <stdio.h>

// void print(int n) {
//     printf("n=%d\n", n);
// }

// int mul3plus1(int n) {
//     return n * 3 + 1;
// }

// int div2(int n) {
//     return n / 2;
// }

// // khai báo các tham s? cho các con tr? hàm odd, even và output
// void simulate(int n, int (*odd)(int), int (*even)(int), void(*output)(int)){
//     (*output)(n);
//     if (n == 1) return;
//     if (n % 2 == 0) {
//         n = (*even)(n);
//     } else {
//         n = (*odd)(n);
//     }
//     simulate(n, odd, even, output);
// }
// int main() {
//     int (*odd)(int) = mul3plus1;
//     int (*even)(int) = div2;
//    	void(*output)(int) = print;

//     int n;
//     scanf("%d", &n);
//     simulate(n, odd, even, output);

//     return 0;
// }

//Giả thuyết Collatz: bắt đầu từ số dương  n  bất kỳ, nếu  n
//   chẵn thì chia 2, nếu lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến  n=1.
// Hãy viết chương trình mô phỏng lại quá trình biến đổi để kiếm chứng giả thuyết với giá trị của  n
//   nhập từ bàn phím.

#include<bits/stdc++.h>

using namespace std;

void print(int n) {
    cout << "n = " << n << endl;
}

int even(int n) {
    return n / 2;
}

int odd(int n) {
    return n * 3 + 1;
}

void collatz(int n, void (*printPtr)(int), int (*evenPtr)(int), int (*oddPtr)(int)) {
    (*printPtr)(n);
    if(n == 1) {
        return;
    }
    if(n % 2 == 0) {
        n = (*evenPtr)(n);
    } else {   
        n = (*oddPtr)(n);
    }
    collatz(n, printPtr, evenPtr, oddPtr);
}

int main() {
    int n;
    do {
        cin >> n;
    } while (n <= 0);

    void (*printPtr)(int) = print;
    int (*evenPtr)(int) = even;
    int (*oddPtr)(int) = odd;

    collatz(n, printPtr, evenPtr, oddPtr);

    return 0;
}