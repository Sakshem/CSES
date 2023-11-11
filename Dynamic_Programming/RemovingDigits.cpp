#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e6, MOD=1e9 + 7;
ll dp[mxN + 1];
void test_case() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        int j = i;
        while (j > 0) {
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
            j /= 10;
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
