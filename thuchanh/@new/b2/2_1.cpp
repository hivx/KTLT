// #include <stdio.h>
// #include <math.h>

// float get_hypotenuse(float x, float y) {
//     return sqrt(x*x+y*y);
// }

// int main(){
//     float x, y;
//     scanf("%f%f", &x, &y);

//     float z = get_hypotenuse(x, y);
//     printf("z = %.2f\n", z);

//     return 0;
// }
// //Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.

#include<bits/stdc++.h>

using namespace std;

float edge(float a, float b) {
    return sqrt(a*a +b*b);
}

int main() {
    float a, b;
    cin >> a >> b;

    cout << fixed << setprecision(2) << edge(a, b);

    return 0;
}