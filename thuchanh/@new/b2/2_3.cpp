// #include <stdio.h>

// int get_value(int x, int a=2, int b=1, int c=0){
//     return a*x*x+b*x+c;
// }
// int main(){
//     int x;
//     scanf("%d", &x);

//     int a = 2;
//     int b = 1;
//     int c = 0;

//     scanf("%d %d %d", &a, &b, &c);

//     printf("a=2, b=1, c=0: %d\n", get_value(x));
//     printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
//     printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
//     printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));

//     return 0;
// }
//Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. 
//In ra giá trị  ax2+bx+c  với a, b, c định sẵn.

#include<bits/stdc++.h>

using namespace std;

int calc( int x, int a = 1, int b = 1, int c = 1) {
    return a*x*x + b*x + c;
}

int main() {
    int x;
    do {
        cin >> x;
    } while (x >= 100);

    int a = 1, b = 1, c = 1;
    cin >> a >> b >> c;

    //cout << calc(x, a, b, c);
    cout << calc(x, a, b);
    
    return 0;
}