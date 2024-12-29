// Bài tập 4
// Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng,
// trả về số lượng số chẵn trong mảng.

#include <stdio.h>

int counteven(int* arr, int size){
    int count = 0;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < size; ++i) {if (arr[i]%2==0) {++count;}}

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {scanf("%d", &arr[i]);}

    printf("%d", counteven (arr, n));
    
    return 0;
}