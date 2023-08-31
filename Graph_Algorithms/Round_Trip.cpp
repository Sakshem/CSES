#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool visited[100005];
vector<int> parent(100005);
vector<int> ans;
void dfs(int node, int parent_node = -1) {
    parent[node] = parent_node;
    visited[node] = true;
    for (auto i : edges[node]) {
        if (i == parent_node) {
            continue;
        }
        if (visited[i]) {
            int node_copy = node;
            while (node != i) {
                ans.push_back(node);
                node = parent[node];
            }
            ans.push_back(i);
            ans.push_back(node_copy);
            cout << ans.size() << '\n';
            for (auto a : ans) cout << a + 1 << ' ';
            cout << '\n';
            exit(0);
        }
        else {
            dfs(i, node);
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
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
