#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m, s, e;

void dijkstra(int s, int e, const vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& prev) {
    dist.assign(n + 1, INF);
    prev.assign(n + 1, -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void floydWarshall(const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& distMatrix) {
    distMatrix.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i) distMatrix[i][i] = 0;

    for (int u = 1; u <= n; ++u) {
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            distMatrix[u][v] = min(distMatrix[u][v], w);
        }
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (distMatrix[i][k] < INF && distMatrix[k][j] < INF)
                    distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
}

vector<int> reconstructPath(int s, int e, const vector<int>& prev) {
    vector<int> path;
    for (int at = e; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    if (path[0] == s) return path;
    else return {};  // No path
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    fin >> n >> m >> s >> e;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        adj[u].push_back(make_pair(v, d));
    }

    // Dijkstra: shortest path from s to e
    vector<int> dist, prev;
    dijkstra(s, e, adj, dist, prev);
    vector<int> path = reconstructPath(s, e, prev);

    // Output part 1
    if (dist[e] == INF) {
        fout << "INF\n\n";
    } else {
        fout << dist[e] << "\n";
        for (size_t i = 0; i < path.size(); ++i) {
            fout << path[i];
            if (i + 1 < path.size()) fout << " ";
        }
        fout << "\n";
    }

    // Floyd-Warshall for all pairs
    vector<vector<int>> distMatrix;
    floydWarshall(adj, distMatrix);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (distMatrix[i][j] >= INF)
                fout << "INF";
            else
                fout << distMatrix[i][j];
            if (j < n) fout << " ";
        }
        fout << "\n";
    }

    return 0;
}
