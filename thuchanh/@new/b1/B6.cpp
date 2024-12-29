// Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
// Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].

#include<stdio.h>

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        l++;
        r--;
    }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        l++;
        r--;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    reversearray(arr, n);
        for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    ptr_reversearray(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;

// void nouseptr(vector<double>& a, int n) {
//     int l = 0, r = n - 1;
//     double tmp;
//     while (l < r) {
//         tmp = a[l];
//         a[l] = a[r];
//         a[r] = tmp;

//         l++;
//         r--;
//     }
// }

// void useptr(double* a, int n) {
//     int l = 0, r = n - 1;
//     double tmp;
//     while (l < r) {
//         tmp = *(a + l);
//         *(a + l) = *(a + r);
//         *(a + r) = tmp;

//         l++;
//         r--;
//     }
// }

// void print(vector<double> a, int n, string s) {
//     cout << s << endl;
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<double> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     nouseptr(a, n);
//     print(a, n, "Dao nguoc mang khong dung con tro:");

//     nouseptr(a, n);
//     print(a, n, "Dao nguoc mang dung con tro:");

//     return 0;
// }
