#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e6, MOD=1e9 + 7;
ll dp[mxN], c[100 + 1];
void test_case() {
    int n, sum; cin >> n >> sum;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] <= i) {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }
    cout << dp[sum] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
