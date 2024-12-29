#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct bigNum {
    char sign;  // '0' for negative, '1' for positive
    string num; // string representation of the absolute value
};

// Khai báo các hàm
bigNum add(bigNum a, bigNum b);
bigNum subtract(bigNum a, bigNum b);
bigNum multiply(bigNum a, bigNum b);
bigNum calculate(bigNum a, bigNum b);
void printBigNum(bigNum num);

// Hàm cộng 2 số nguyên lớn
bigNum add(bigNum a, bigNum b) {
    // Xử lý dấu
    if (a.sign == b.sign) {
        string result;
        int carry = 0;
        int lenA = a.num.length(), lenB = b.num.length();
        int i = lenA - 1, j = lenB - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a.num[i] - '0';
            if (j >= 0) sum += b.num[j] - '0';
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
            i--; j--;
        }
        
        reverse(result.begin(), result.end());
        return {a.sign, result};
    } else {
        // Nếu dấu khác nhau thì trừ
        if (a.sign == '1') {
            a.sign = '0';  // Đổi dấu a và cộng
            return subtract(b, a);
        } else {
            b.sign = '0';  // Đổi dấu b và cộng
            return subtract(a, b);
        }
    }
}

// Hàm trừ 2 số nguyên lớn
bigNum subtract(bigNum a, bigNum b) {
    // Đảm bảo a >= b
    if (a.sign != b.sign) {
        b.sign = a.sign;  // Đổi dấu và cộng
        return add(a, b);
    }
    string result;
    int borrow = 0;
    int lenA = a.num.length(), lenB = b.num.length();
    int i = lenA - 1, j = lenB - 1;
    
    while (i >= 0 || j >= 0 || borrow) {
        int sub = (a.num[i] - '0') - (j >= 0 ? b.num[j] - '0' : 0) - borrow;
        borrow = (sub < 0) ? 1 : 0;
        if (borrow) sub += 10;
        result.push_back(sub + '0');
        i--; j--;
    }
    
    reverse(result.begin(), result.end());
    return {a.sign, result};
}

// Hàm nhân 2 số nguyên lớn
bigNum multiply(bigNum a, bigNum b) {
    string result(a.num.length() + b.num.length(), '0');
    int sign = (a.sign == b.sign) ? 1 : 0;
    
    for (int i = a.num.length() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = b.num.length() - 1; j >= 0; j--) {
            int mul = (a.num[i] - '0') * (b.num[j] - '0') + carry + (result[i + j + 1] - '0');
            carry = mul / 10;
            result[i + j + 1] = mul % 10 + '0';
        }
        result[i] = carry + '0';
    }

    // Remove leading zeros
    int start = 0;
    while (start < result.length() && result[start] == '0') start++;
    result = result.substr(start);
    if (result.empty()) result = "0";  // Nếu kết quả là 0
    return {sign ? '1' : '0', result};
}

// Hàm tính biểu thức ab - 3a + 4b
bigNum calculate(bigNum a, bigNum b) {
    bigNum ab = multiply(a, b); // Tính ab
    bigNum threeA = multiply({'1', "3"}, a); // 3a
    bigNum fourB = multiply({'1', "4"}, b); // 4b
    bigNum result = subtract(ab, threeA); // Tính ab - 3a
    result = add(result, fourB);  // Tính (ab - 3a) + 4b
    return result;
}

// Hàm in ra số nguyên lớn theo định dạng
void printBigNum(bigNum num) {
    cout << num.sign << num.num << endl;
}

int main() {
    string a_str, b_str;
    cin >> a_str >> b_str;

    bigNum a = {a_str[0], a_str.substr(1)};
    bigNum b = {b_str[0], b_str.substr(1)};
    
    bigNum result = calculate(a, b);
    printBigNum(result);
    
    return 0;
}
/*
0121807015
1347227347
*/
