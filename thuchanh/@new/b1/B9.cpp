// #include <stdio.h>

// void generateSubsequences(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             for (int k = i; k <= j; k++) {
//                 printf("%d ", arr[k]);
//             }
//             printf("\n");
//         }
//     }
// }

// int main() {
//     int n;

//     scanf("%d", &n);

//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     generateSubsequences(arr, n);

//     return 0;
// }

// Viết chương trình in ra tất cả các dãy con của một dãy cho trước. Ví dụ dãy 1 3 4 2 có các dãy con sau:
// 1
// 1 3
// 1 3 4
// 1 3 4 2
// 3
// 3 4
// 3 4 2
// 4
// 4 2
// 2

#include <bits/stdc++.h>


using namespace std;

void process(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k <= j; k++) {
            cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    process(arr, n);

    return 0;
}