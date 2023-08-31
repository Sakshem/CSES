#include<bits/stdc++.h> 
using namespace std; 
const int mxN=1e3, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int n, m, si, sj, ti, tj, d[mxN][mxN];
const char dc[4] = {'D', 'R', 'U', 'L'};
string s[mxN], p[mxN];
bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}
void test_case() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                si = i; sj = j;
            }
            else if (s[i][j] == 'B') {
                ti = i; tj = j;
                s[i][j] = '.';
            }
        }
        p[i] = string(m, 0);
    }
    queue<array<int, 2>> q;
    q.push({si, sj});
    while (!q.empty()) {
        array<int, 2> u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = u[0] + di[k];
            int nj = u[1] + dj[k];
            if (!is_valid(ni, nj)) continue;
            q.push({ni, nj});
            s[ni][nj] = '#';
            d[ni][nj] = k;
            p[ni][nj]=dc[k];
        }
    }
    if (p[ti][tj]) {
        cout << "YES" << '\n';
        string t;
        while (ti ^ si || tj ^ sj) {
            t += p[ti][tj];
            int dd = d[ti][tj] ^ 2;
            ti += di[dd];
            tj += dj[dd];
        }
        reverse(t.begin(), t.end());
        cout << t.size() << '\n';
        cout << t << '\n';
    }
    else cout << "NO" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
