#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<pair<ll, ll>> edges1[100005], edges2[100005]; // pair<int, int> = destination, cost
ll d1[100005], d2[100005];
void solve(int u, vector<pair<ll, ll>> edges[100005], ll d[100005]) {
    memset(d, 0x3f, sizeof(d1));
    d[u] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({u, 0});
    while (!pq.empty()) {
        pair<ll, ll> p = pq.top();
        pq.pop();
        if (p.second > d[p.first]) {
            continue;
        }
        for (auto x : edges[p.first]) {
            if (d[x.first] > p.second + x.second) {
                d[x.first] = p.second + x.second;
                pq.push({x.first, d[x.first]});
            }
        }
    }
}
void test_case() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;
        edges1[a].push_back({b, c});
        edges2[b].push_back({a, c});
    }
    solve(0, edges1, d1);
    solve(n - 1, edges2, d2);
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (auto j : edges1[i]) {
            ans = min(ans, d1[i] + d2[j.first] + j.second/2);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
