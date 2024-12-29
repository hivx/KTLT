#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> A(N+1);  // Các hệ số của A(x)
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M+1);  // Các hệ số của B(x)
    for (int i = 0; i <= M; ++i) {
        cin >> B[i];
    }

    int degreeC = N + M - 1;  // Bậc của C(x)
    vector<int> C(degreeC + 1, 0);  // Các hệ số của C(x), khởi tạo với 0

    // Tính tích của hai đa thức A(x) và B(x)
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            C[i + j] += A[i] * B[j];
        }
    }

    int result = 0;
    for (int i = 0; i <= degreeC+1; ++i) {
        result ^= C[i];  // XOR từng hệ số trong C(x)
    }

    // In kết quả
    cout << result << endl;
    return 0;
}
