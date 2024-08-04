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
bool seive(int n)
{
      memset(prime, 1, n + 1);
      for (int i = 2; i * i < n; i++)
            if (prime[i] == 1)
                  for (int j = i * i; j <= n; j += i)
                        prime[j] = 0;
}
bool checkSorted(vector<int> &a)
{
      for (int i = 0; i < a.size() - 1; i++)
      {
            if (a[i] > a[i + 1])
                  return false;
      }
      return true;
}
template <typename T>
void takeInput(vector<T> &a, int n)
{
      for (int i = 0; i < n; i++)
      {
            T ele;
            cin >> ele;
            a[i] = ele;
      }
}
template <typename T>
void printArr(vector<T> &a)
{
      cout << endl;
      for (auto it : a)
      {
            cout << it << " ";
      }
      cout << endl;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            b[i][j] = ch - '0';
        }
    }
    
    // Check if transformation is possible
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] != b[i][j]) {
                int diff = (b[i][j] - a[i][j] + 3) % 3;
                a[i][j] = (a[i][j] + diff) % 3;
                a[i+1][j] = (a[i+1][j] + diff) % 3;
                a[i][j+1] = (a[i][j+1] + diff) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + diff) % 3;
            }
        }
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
    }
    
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      int t;
      cin >> t;
      while (t--)
      {
            solve();
      }
      return 0;
}