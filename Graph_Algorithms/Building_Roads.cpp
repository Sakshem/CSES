#include<bits/stdc++.h>
using namespace std;
vector<int> edges[100005];
bool visited[100005];
void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto i : edges[node]) {
        if (!visited[i])
            dfs(i);
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
    memset(visited, false, 100005);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans.push_back(i + 1);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[0] << ' ' << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
