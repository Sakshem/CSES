#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool visited[100005];
bool color[100005];
bool possible = true;
void dfs(int node, bool c) {
    if (visited[node]) return;
    visited[node] = true;
    color[node] = c;
    for (auto i : edges[node]) {
        if (!visited[i])
            dfs(i, c ^ 1);
        else {
            if (color[i] == c) {
                possible = false;
            }
        }
    }
}
void test_case() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, false);
        }
    }
    if (possible) {
        for (int i = 0; i < n; i++) {
            int value = color[i] ? 2 : 1;
            cout << value << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
