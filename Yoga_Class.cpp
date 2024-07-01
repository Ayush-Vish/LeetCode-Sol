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

int f(int n, int x, int y) {
    int type2Sessions = n / 2; // Maximum number of Type 2 sessions
    int earnings = type2Sessions * y; // Earnings from Type 2 sessions
    if (n % 2 == 1) {
        // If there's an odd hour left, add a Type 1 session
        earnings += x;
    }
    return earnings;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    // Adjusting the strategy to maximize earnings
    int maxEarnings = (n % 2 == 0) ? max(f(n, x, y), (n / 2) * y) : max(f(n, x, y), ((n - 1) / 2) * y + x);
    cout << maxEarnings << endl;
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