#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = 1e18;
int n, m;
void floyd_warshall(vector<vector<ll>>& dist) {
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
void test_case() {
    int q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e18));
    for (int i = 0; i < m; i++) {
        ll u, v, cost; cin >> u >> v >> cost;
        --u; --v;
        dist[u][v] = min(dist[u][v], cost);
        dist[v][u] = min(dist[v][u], cost);
    }
    floyd_warshall(dist);
    for (int i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        --a; --b;
        cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
