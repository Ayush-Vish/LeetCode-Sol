#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }



void solve() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    // cout << f(a, b) << endl;
    for (int i=1 ; i <=a ; i ++ ) {
        for(int j=1 ; j <=b ; j ++ ) {
            if(i == j ) {
                dp[i][j] = 0;
            }else {
                for(int k=1 ; k <i ; k ++ ) {
                    dp[i][j] = min(dp[i][j],1 + dp[k][j] + dp[i-k][j]);
                }
                for(int k=1 ; k<j;k++ ) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }
    cout << dp[a][b];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}