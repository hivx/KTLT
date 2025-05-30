// Bài tập 7
// Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím. 
// Sau đó sắp xếp mảng theo thứ tự tăng dần. 
// Hiển thị danh sách mảng trước và sau khi sắp xếp.
// Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.

// #include <stdio.h>
// #include <stdlib.h>

// int *a;
// int n, tmp;

// int main(){
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
    
//     //#Allocate memory
//     a = (int*)malloc(sizeof(int));
//     if (a == NULL) {
//         printf("Cấp phát bộ nhớ thất bại!\n");
//         return 1;
//     }

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
    
//     for(int i = 0; i < n; i++)
//         scanf("%d", a + i); 
    
//     printf("The input array is: \n");
//     for(int i = 0; i < n; i++)
//         printf("%d ", *(a + i));
//     printf("\n");
    
//     //#Sort array   
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (*(a + j) > *(a + j + 1)) {
//                 tmp = *(a + j);
//                 *(a + j) = *(a + j + 1);
//                 *(a + j + 1) = tmp;
//             }
//         }
//     }
//     /*****************
//     # YOUR CODE HERE #
//     *****************/
    
//     printf("The sorted array is: \n");
//     for(int i = 0; i < n; i++)
//         printf("%d ", *(a + i));
//     printf("\n");
    
//     delete [] a;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(int* a, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a + j, a + j + 1);
                swapped = true;
            }
        }
        //swapped == false
        if (!swapped) {
            break;
        }
    }
}

void print(int* a, int n, string s) {
    cout << s << " ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}   

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    print(a, n, "mang ban dau la:");

    sort(a, n);
    print(a, n, "mang da sap xep la:");

    delete[] a;

    return 0;
}