#include<bits/stdc++.h>
using namespace std;
int n, m;
bool is_valid(int i, int j, vector<vector<char>>& s) {
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.'; 
}
void dfs(int i, int j, vector<vector<char>>& s) {
    s[i][j] = '#';
    if (is_valid(i - 1, j, s)) {
        dfs(i - 1, j, s);
    }
    if (is_valid(i, j - 1, s)) {
        dfs(i, j - 1, s);
    }
    if (is_valid(i + 1, j, s)) {
        dfs(i + 1, j, s);
    }
    if (is_valid(i, j + 1, s)) {
        dfs(i, j + 1, s);
    }
}
void test_case() {
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    int connected_components = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_valid(i, j, s)) {
                dfs(i, j, s);
                connected_components++;
            }
        }
    }
    cout << connected_components << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_case();
    return 0;
}
