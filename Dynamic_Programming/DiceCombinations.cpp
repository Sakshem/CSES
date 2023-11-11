#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e6, MOD = 1e9 + 7;
ll dp[mxN + 1];
void test_case() {
    int n; cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD; 
        }
    }
 
    cout << dp[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}

