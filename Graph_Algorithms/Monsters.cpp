#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e3;
string s[mxN];
bool visited[mxN][mxN];
int n, m, startI, startJ, d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};
bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.' && !visited[i][j];
}
void bfs(vector<array<int, 2>> v, int d[mxN][mxN], int p[mxN][mxN]) {
    queue<array<int, 2>> q;
    memset(visited, false, sizeof(visited));
    memset(d, 0x3f, sizeof(d1));
    for (auto a : v) {
        q.push(a);
        visited[a[0]][a[1]] = true;
        d[a[0]][a[1]] = 1;
    }
    while (!q.empty()) {
        int i = q.front()[0];
        int j = q.front()[1];
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!is_valid(ni, nj)) continue;
            q.push({ni, nj});
            visited[ni][nj] = true;
            d[ni][nj] = d[i][j] + 1;
            p[ni][nj] = k;
        }
    }
}
void test_case() {
    cin >> n >> m;
    vector<array<int, 2>> monster_pos;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                startI = i, startJ = j, s[i][j] = '.';
            }
            else if (s[i][j] == 'M') {
                monster_pos.push_back({i, j});
                s[i][j] = '.';
            }
        }
    }
    bfs({{startI, startJ}}, d1, p1);
    bfs(monster_pos, d2, p2);
    int ti = -1, tj;
    for (int i = 0; i < n; i++) {
        if (d1[i][0] < d2[i][0]) {
            ti = i, tj = 0;
        }
        if (d1[i][m - 1] < d2[i][m - 1]){
            ti = i, tj = m - 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (d1[0][j] < d2[0][j]) {
            ti = 0, tj = j;
        }
        if (d1[n - 1][j] < d2[n - 1][j]) {
            ti = n - 1, tj = j;
        }
    }

    if (ti != -1) {
        string t;
        while (ti != startI || tj != startJ) {
            t += dc[p1[ti][tj]];
            int dd = p1[ti][tj] ^ 2; 
            ti += di[dd];
            tj += dj[dd];
        }
        reverse(t.begin(), t.end());
        cout << "YES" << '\n';
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
