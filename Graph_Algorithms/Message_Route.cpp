#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool visited[100005];
int parent[100005];
void test_case() {
    int n, m;
    vector<int> path;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(parent, -1, 4*n);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : edges[node]) {
            if (parent[i] < 0) {
                parent[i] = node;
                q.push(i);
            }
        }
    }
    if (parent[n - 1] < 0) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        int node = n - 1;
        while (node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(0);
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (auto i : path) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
