#include <vector>
#include <list>
#include <iostream>
#include <queue>

using namespace std;

void bfs(const vector<list<int>> &adj) {
    queue<int> Q;
    vector<bool> was(adj.size(), false);

    Q.push(1); // Bắt đầu từ đỉnh 1 (theo giả định bài toán)
    was[1] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        cout << u << endl; // In đỉnh đang xét

        for (int v : adj[u]) {
            if (!was[v]) {
                was[v] = true;
                Q.push(v);
            }
        }
    }

    cout << endl;
}

int main() {
    int n = 7; // Số đỉnh
    vector<list<int>> adj(n + 1); // Đồ thị 1-based, chứa các đỉnh từ 1 đến n

    // Thêm cạnh vào đồ thị
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);

    // Gọi BFS
    bfs(adj);

    return 0;
}
