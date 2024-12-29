#include <vector>
#include <list>
#include <iostream>
#include <stack>

// Duyệt đồ thị theo chiều sâu (DFS)
void dfs(std::vector<std::list<int>> &adj) {
    std::stack<int> S;
    std::vector<bool> visited(adj.size(), false);

    S.push(1); // Bắt đầu từ đỉnh 1 (theo giả định bài toán)

    while (!S.empty()) {
        int u = S.top();

        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << std::endl; // In đỉnh đã thăm
        }

        if (!adj[u].empty()) {
            int v = adj[u].front();
            adj[u].pop_front();

            if (!visited[v]) {
                S.push(v);
            }
        } else {
            S.pop();
        }
    }
}

int main() {
    int n = 7; // Số đỉnh
    std::vector<std::list<int>> adj;
    adj.resize(n + 1); // Đồ thị 1-based, chứa các đỉnh từ 1 đến n

    // Thêm cạnh vào đồ thị
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);

    // Gọi DFS
    dfs(adj);

    return 0;
}
