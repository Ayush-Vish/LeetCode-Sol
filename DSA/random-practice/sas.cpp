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
void solve()
{
      // Write your greatness here
      int n;
      string s;
      cin >> n;
      cin >> s;
      int a = 0;
      int b = 0;
      int c = 0;
      int d = 0;
      int q = 0;
      for (int i = 0; i < 4 * n; i++)
      {
            if (s[i] == 'A')
            {
                  a++;
            }
            else if (s[i] == 'B')
            {
                  b++;
            }
            else if (s[i] == 'C')
            {
                  c++;
            }
            else if (s[i] == 'D')
            {
                  d++;
            }
            else
            {
                  q++;
            }
      }
      int ans = 0;

      if (a >= n)
      {
            ans += n;
      }
      else if (a < n)
      {
            ans += a;
      }
      if (b >= n)
      {
            ans += n;
      }
      else if (b < n)
      {
            ans += b;
      }
      if (c >= n)
      {
            ans += n;
      }
      else if (c < n)
      {
            ans += c;
      }
      if (d >= n)
      {
            ans += n;
      }
      else if (d < n)
      {
            ans += d;
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
      while (t--)
      {
            solve();
      }
      return 0;
}