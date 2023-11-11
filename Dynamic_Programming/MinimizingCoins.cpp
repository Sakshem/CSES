#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e6, MOD=1e9 + 7;
ll c[100];
ll dp[mxN + 1];
void test_case() {
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= x; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (c[j] <= i) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    // for (int i = 1; i <= x; i++) {
    //     cout << "dp[" << i << "]: " << dp[i] << ' ';
    // }
    // cout << '\n';
    if (dp[x] >= 1e9) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
