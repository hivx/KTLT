#include <iostream>
#include <cstring>

using namespace std;

const int N = 128;

struct Matrix {
    unsigned int mat[N][N];

    Matrix() {
        memset(mat, 0, sizeof mat);
    }
};

bool operator == (const Matrix &a, const Matrix &b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j]) return false;
        }
    }
    return true;
}

// Hàm nhân ma trận theo phương pháp đơn giản (O(N^3))
Matrix multiply_naive(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

// Hàm nhân ma trận tối ưu (O(N^3)) sử dụng blocking
Matrix multiply_fast(const Matrix &a, const Matrix &b) {
    Matrix c;
    const int BLOCK_SIZE = 32; // Kích thước block tùy chọn, có thể thay đổi tùy theo hệ thống
    
    // Chia ma trận thành các block nhỏ hơn để tận dụng cache
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                // Nhân các block nhỏ
                for (int ii = i; ii < min(i + BLOCK_SIZE, N); ++ii) {
                    for (int jj = j; jj < min(j + BLOCK_SIZE, N); ++jj) {
                        for (int kk = k; kk < min(k + BLOCK_SIZE, N); ++kk) {
                            c.mat[ii][jj] += a.mat[ii][kk] * b.mat[kk][jj];
                        }
                    }
                }
            }
        }
    }
    return c;
}

Matrix gen_random_matrix() {
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix &result) {
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;

    printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

int main() {
    base = gen_random_matrix();

    Matrix a, b;
    printf("Slow version\n");
    double slow = benchmark(multiply_naive, a);
    printf("Fast version\n");
    double fast = benchmark(multiply_fast, b);

    if (a == b) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}
