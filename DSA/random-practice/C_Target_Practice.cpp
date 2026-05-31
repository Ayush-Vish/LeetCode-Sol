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
int prime[1];
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
/**
* Author: god_ayushv
*/
void solve()
{
    // Write your greatness here
    int n = 10;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int direction = 0;
    int cost = 1;
    int ans = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                if (v[top][i] == 'X') {
                    ans += cost;
                }
            }
            top++;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                if (v[i][right] == 'X') {
                    ans += cost;
                }
            }
            right--;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                if (v[bottom][i] == 'X') {
                    ans += cost;
                }
            }
            bottom--;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                if (v[i][left] == 'X') {
                    ans += cost;
                }
            }
            left++;
        }
        direction = (direction + 1) % 4;
        if (direction == 0) {
            cost++;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}