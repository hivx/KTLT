// #include <stdio.h>
// #include <stdlib.h>

// void inputMatrix(int** matrix, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }
// }

// void printMatrix(int** matrix, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int** addMatrices(int** A, int** B, int n) {
//     int** result = (int**)malloc(n * sizeof(int*));
//     for (int i = 0; i < n; i++) {
//         result[i] = (int*)malloc(n * sizeof(int));
//         for (int j = 0; j < n; j++) {
//             result[i][j] = A[i][j] + B[i][j];
//         }
//     }
//     return result;
// }

// int** multiplyMatrices(int** A, int** B, int n) {
//     int** result = (int**)malloc(n * sizeof(int*));
//     for (int i = 0; i < n; i++) {
//         result[i] = (int*)malloc(n * sizeof(int));
//         for (int j = 0; j < n; j++) {
//             result[i][j] = 0;
//             for (int k = 0; k < n; k++) {
//                 result[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
//     return result;
// }

// void deleteMatrix(int** matrix, int n) {
//     for (int i = 0; i < n; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     int** A = (int**)malloc(n * sizeof(int*));
//     int** B = (int**)malloc(n * sizeof(int*));
    
//     for (int i = 0; i < n; i++) {
//         A[i] = (int*)malloc(n * sizeof(int));
//         B[i] = (int*)malloc(n * sizeof(int));
//     }

//     inputMatrix(A, n);
//     inputMatrix(B, n);

//     int** sum = addMatrices(A, B, n);
//     int** product = multiplyMatrices(A, B, n);

//     printMatrix(sum, n);
//     printMatrix(product, n);

//     deleteMatrix(A, n);
//     deleteMatrix(B, n);
//     deleteMatrix(sum, n);
//     deleteMatrix(product, n);

//     return 0;
// }
// Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím. 
// Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
// Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.

#include<bits/stdc++.h>

using namespace std;

void alloc_mem(int*** mt, int n) {
    *mt = new int*[n];
    for(int i = 0; i < n; i++) {
        (*mt)[i] = new int[n];
        for (int j = 0; j < n; j++) {
            (*mt)[i][j] = 0; // Khởi tạo các phần tử về 0
        }
    }
}

void free_mem(int** mt, int n) {
    for(int i = 0; i < n; i++) {
        delete[] mt[i];
    }
    delete[] mt;
}

void input(int** mt, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mt[i][j];
        }
    }
}

void printmt(int** arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int** summt(int** arr1, int** arr2, int n) {
    int** arr3;
    alloc_mem(&arr3, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return arr3;
}

int** multiplymt(int** arr1, int** arr2, int n) {
    int** arr3;
    alloc_mem(&arr3, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                arr3[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
    return arr3;
}

int main() {
    int n; cin >> n;
    
    int** arr1;
    alloc_mem(&arr1, n);
    input(arr1, n);
    
    int** arr2;
    alloc_mem(&arr2, n);
    input(arr2, n);

    printmt(summt(arr1, arr2, n), n);

    printmt(multiplymt(arr1, arr2, n), n);

    free_mem(arr1, n);
    free_mem(arr2, n);

    return 0;
}