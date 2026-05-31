#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool check(int row, int col, vector<vector<char>> &v) {
    for (int i = 0; i < row; i++) {
        if (v[i][col] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (v[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j < v.size(); i--, j++) {
        if (v[i][j] == 'Q') return false;
    }
    return true;
}

void nQueens(int row, vector<vector<char>> &v, int &ans) {
    if (row == v.size()) {
        ans++;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (check(row, i, v) && v[row][i] != '*') {
            v[row][i] = 'Q';
            nQueens(row + 1, v, ans);
            v[row][i] = '.';
        }
    }
}

void solve() {
    int n = 8;
    vector<vector<char>> v(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    nQueens(0, v, ans);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}