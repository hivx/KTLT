#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e5 + 7;

int n, s, quantities[MAX], values[MAX];
ll result = 0;
multiset<pair<int, int>, greater<pair<int, int>>> itemSet;

int main()
{
    // Đọc vào số lượng sản phẩm và số lượng cần chọn
    cin >> n >> s;

    // Đọc vào thông tin các sản phẩm: số lượng và giá trị
    for(int i = 1; i <= n; i++)
    {
        cin >> quantities[i] >> values[i];
        // Thêm vào multiset theo thứ tự giảm dần của giá trị
        itemSet.insert({values[i], quantities[i]});
        result += quantities[i];
    }

    // Lặp cho đến khi hết sản phẩm hoặc không còn sản phẩm để chọn
    while (!itemSet.empty() && s > 0)
    {
        // Lấy phần tử có giá trị cao nhất
        auto top = itemSet.begin();
        auto currentItem = (*top);
        itemSet.erase(top);

        // Nếu số lượng cần chọn nhỏ hơn số lượng của sản phẩm hiện tại
        if (s < (currentItem.second / currentItem.first))
        {
            result -= currentItem.first * s;
            s = 0;
        }
        else
        {
            result -= currentItem.first * (currentItem.second / currentItem.first);
            s -= (currentItem.second / currentItem.first);
        }

        // Cập nhật lại số lượng của sản phẩm và nếu còn lại, thêm lại vào multiset
        currentItem.second -= currentItem.first * (currentItem.second / currentItem.first);
        if (currentItem.second > 0)
            itemSet.insert({currentItem.second, currentItem.second});
    }

    // In ra kết quả cuối cùng
    cout << result;
}
