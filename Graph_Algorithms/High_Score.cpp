#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n, m;
vector<pair<ll, ll>> edges[2503]; // pair<int, int> = {destination, weight}
ll d[2503], ans[2503];
void test_case() {
    memset(d, 0xc0, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b, x; cin >> a >> b >> x;
        --a; --b;
        edges[a].push_back({b, x});
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto a : edges[j]) {
                d[a.first] = max(d[a.first], d[j] + a.second);
            }
        }
        ans[i] = d[n - 1];
    }

    if (n > 1 && ans[n - 2] < ans[n - 1]) {
        cout << -1 << '\n';
    }
    else {
        cout << ans[n - 1] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
