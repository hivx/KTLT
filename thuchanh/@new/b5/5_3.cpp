#include <iostream>
#include <stack>
using namespace std;


int par(string str) {
    int a = str.length();
    stack<char> S;
    char x; //biến y không cần thiết
    for (int i = 0; i < a; i++) {
        x = str[i];
        if (x == '(' || x == '[' || x == '{') {
            S.push(x);
        } else {
            // Kiểm tra ngăn xếp rỗng trước khi gọi top()
            if (S.empty()) return 0; // Nếu ngăn xếp rỗng mà gặp dấu đóng, trả về 0
            if (x == ')') {
                if (S.top() == '(') {
                    S.pop();
                } else return 0;
            } else if (x == ']') {
                if (S.top() == '[') {
                    S.pop();
                } else return 0;
            } else if (x == '}') {
                if (S.top() == '{') {
                    S.pop();
                } else return 0;
            }
        }
    }
    // Kiểm tra ngăn xếp rỗng sau khi duyệt hết chuỗi
    //S.top() != NULL không đúng, vì top() trả về giá trị của phần tử đầu ngăn xếp, không phải là con trỏ
    if (!S.empty()) { // Nếu ngăn xếp không rỗng, trả về 0
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n;
    string str;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        cout << par(str) << endl;
    }
    
    return 0;
}