#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // ?? th? co h??ng
    }

    queue<int> q;
    q.push(X);
    dist[X] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << dist[Y] << endl;
    return 0;
}
