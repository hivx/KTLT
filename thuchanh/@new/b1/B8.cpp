// // Bài tập 8
// // Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím. 
// // Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.

// // Lưu ý: Khi viết hàm cấp phát bộ nhớ cho một ma trận hai chiều biểu diễn bởi con trỏ int **mt, 
// // nếu ta truyền con trỏ theo kiểu địa chỉ void allocate(int **mt, int m, int n) sẽ dẫn tới việc cấp phát bộ nhớ cho một bản sao của con trỏ **mt. 
// // Do đó, sau khi gọi hàm thì con trỏ **mt gốc vẫn không được cấp phát bộ nhớ. Để cấp phát thành công cần truyền con trỏ theo dạng địa chỉ, 
// // ví dụ sử dụng con trỏ cấp 3 dạng int ***mt.

// #include <stdio.h>
// #include <stdlib.h>

// void allocate_mem(int ***mt, int m, int n) {
//     // Cấp phát bộ nhớ cho ma trận
//     *mt = (int **)malloc(m * sizeof(int *));
//     for (int i = 0; i < m; i++) {
//         (*mt)[i] = (int *)malloc(n * sizeof(int));
//     }
// }

// void input(int **mt, int m, int n) {
//     // Nhập các phần tử của ma trận
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("mt[%d][%d] = ", i, j);
//             scanf("%d", &mt[i][j]);
//         }
//     }
// }

// void output(int **mt, int m, int n) {
//     // In tất cả các phần tử của ma trận
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", mt[i][j]);
//         }
//         printf("\n");
//     }
// }

// int process(int **mt, int m, int n) {
//     int tong = 0;
//     // Tính tổng các phần tử chẵn trong ma trận
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (mt[i][j] % 2 == 0) {
//                 tong += mt[i][j];
//             }
//         }
//     }
//     return tong;
// }

// void free_mem(int **mt, int m) {
//     // Giải phóng bộ nhớ
//     for (int i = 0; i < m; i++) {
//         free(mt[i]);
//     }
//     free(mt);
// }

// int main() {
//     int m, n, **mt;
//     printf("Enter m, n = ");
//     scanf("%d%d", &m, &n);
//     allocate_mem(&mt, m, n);
//     input(mt, m, n);
//     output(mt, m, n);
//     printf("The sum of all even elements is %d\n", process(mt, m, n));
//     free_mem(mt, m);
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void allocate_mem(int*** mt, int m, int n) {
    *mt = new int*[m];
    for(int i = 0; i < m; i++) {
        (*mt)[i] = new int [n]; 
    }
}

void free_mem(int** mt, int m) {
    for(int i = 0; i < m; i++) {
        delete[] mt[i];
    }
    delete[] mt;
}

void input(int** mt, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mt[i][j];
        }
    }
}
//int** mt la thao tac voi 1 mang la ban sao cua mt, ko thay doi mt
// int*** mt la thao thao toi mang, su dung con tro tro toi mang
int proc(int** mt, int m, int n) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mt[i][j]%2 == 0) {
                sum += mt[i][j];
            }
        }
    }
    return sum;
}

void print(int** mt, int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int** mt;
    allocate_mem(&mt, m, n);

    input(mt, m, n);

    print(mt, m, n);

    cout << "Tong cac so chan la: " << proc(mt, m, n) << endl;

    free_mem(mt, m);

    return 0;
}