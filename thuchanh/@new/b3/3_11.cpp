#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
int n, r;  // Số đỉnh và số khách hàng
int cost[MAX][MAX];  // Ma trận chi phí
int path[MAX];  // Mảng lưu các điểm trong đường đi
bool visited[MAX];  // Mảng đánh dấu các điểm đã thăm
vector<int> destinations;  // Danh sách các điểm cần thăm
int min_cost, total_cost;  // Biến lưu chi phí nhỏ nhất và tổng chi phí
int start_point, end_point, total_points;  // Điểm bắt đầu, điểm kết thúc, số điểm cần đi qua

bool isValid(int prev_index, int curr_index)
{
    if (visited[destinations[curr_index]])
        return false;
    if (cost[path[prev_index - 1]][destinations[curr_index]] == 0)
        return false;
    return true;
}

void updateSolution()
{
    if (cost[path[total_points - 2]][end_point] == 0)
        return;
    min_cost = min(min_cost, total_cost + cost[path[total_points - 2]][end_point]);
}

void findPaths(int index)
{
    for (int i = 1; i < total_points - 1; i++)
    {
        if (isValid(index, i))
        {
            visited[destinations[i]] = true;
            total_cost += cost[path[index - 1]][destinations[i]];
            path[index] = destinations[i];

            if (index == total_points - 2)
                updateSolution();
            else
                findPaths(index + 1);

            visited[destinations[i]] = false;
            total_cost -= cost[path[index - 1]][destinations[i]];
        }
    }
}

void processCustomerRequest(const string& request)
{
    min_cost = INT_MAX;
    total_cost = 0;
    destinations.clear();

    // Phân tích yêu cầu khách hàng
    stringstream ss(request);
    int point;
    while (ss >> point)
    {
        destinations.push_back(point - 1);
    }

    start_point = destinations[0];
    end_point = destinations[destinations.size() - 1];
    total_points = destinations.size();
    path[0] = start_point;
    path[total_points - 1] = end_point;

    fill(visited, visited + n, false);
    findPaths(1);

    if (min_cost == INT_MAX)
        cout << "0" << endl;
    else
        cout << min_cost << endl;
}

int main() {

    cin >> n >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    cin.ignore();  // Bỏ dòng trống sau input

    while (r--)
    {
        string customer_request;
        getline(cin, customer_request);
        processCustomerRequest(customer_request);
    }

    return 0;
}

// 6 3
// 0 1 2 0 1 1
// 1 0 1 1 1 0
// 0 2 0 1 3 0
// 4 3 1 0 0 0
// 0 0 1 1 0 0
// 1 0 0 0 0 0
// 1 3 5
// 6 3 2 5
// 6 1 2 3 4 5
