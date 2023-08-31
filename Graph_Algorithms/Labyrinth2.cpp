#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e3;
int n, m;
string s[mxN], p[mxN];
vector<char> path;
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
char dc[4] = {'R', 'D', 'L', 'U'};
bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && (s[i][j] == '.' || s[i][j] == 'B');
}
bool bfs(int si, int sj) {
    queue<array<int, 2>> q;
    q.push({si, sj});
    s[si][sj] = '#';
    while (!q.empty()) {
        int i = q.front()[0];
        int j = q.front()[1];
        q.pop();
        if (s[i][j] == 'B') {
            while (true) {
                path.push_back(p[i][j]);
                if (path.back() == 'L') j++;
                if (path.back() == 'R') j--;
                if (path.back() == 'U') i++;
                if (path.back() == 'D') i--;
                if (si == i && sj == j) break;
            }
            return true;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!is_valid(ni, nj)) continue;
            q.push({ni, nj});
            p[ni][nj] = dc[k];
            if (!(s[ni][nj] == 'B')) {
                s[ni][nj] = '#';
            }
        }
    }
    return false;
}
void test_case() {
    int si, sj;
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                si = i, sj = j;
            }
        }
        p[i] = string(m, 0);
    }
    if (bfs(si, sj)) {
        cout << "YES" << '\n';
        cout << path.size() << '\n';
        reverse(path.begin(), path.end());
        for (auto i : path) cout << i;
        cout << '\n';
    }
    else cout << "NO" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
