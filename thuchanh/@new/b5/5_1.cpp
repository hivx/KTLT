#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    //ở đây cần in xuống dòng nên lỗi viết sai
    printf("\n");
}

void process(int i) {
    if (i > n){
        //ở đây cần gọi hàm nên viết sai
        print();
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}