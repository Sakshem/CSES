#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n, m;
vector<pair<ll, ll>> edges[100005]; // pair<ll, ll> - {destination, weight}
bool visited[100005];
ll dists[100005];
void dijkstra(ll source) {
    for (int i = 0; i < n; i++) {
        dists[i] = 1e18; // infinity at the beginning
        visited[i] = false;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dists[source] = 0;
    pq.push({0, source}); // cost, destination
    while (!pq.empty()) {
        pair<ll, ll> current = pq.top();
        pq.pop();
        ll distance = current.first, target = current.second;
        if (visited[target]) continue;

        visited[target] = true;
        for (pair<ll, ll> node : edges[target]) {
            ll node_distance = distance + node.second;
            if (node_distance < dists[node.first]) {
                dists[node.first] = node_distance;
                pq.push({dists[node.first], node.first}); // {cost, destination}
            }
        }
    }
}
void test_case() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        --u; --v;
        edges[u].push_back({v, cost}); // directed graph
    }
    
    dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << dists[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
