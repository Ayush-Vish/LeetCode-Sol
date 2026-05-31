#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
      int n;
      cin >> n;

      vector<int> a(n);
      vector<int> cnt(31, 0);
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
            int x = a[i];
            for (int j = 0; j < 31; j++)
            {
                  cnt[j] += (x >> j) & 1;
            }
      }
      int d = 0;
      for (int i = 0; i < 31; i++)
      {
            d = __gcd(d, cnt[i]);
      }

      for (int i = 1; i <= n; i++)
      {
            if (d% i  == 0)
            {
                  cout << i << " ";
            }
      }
      cout << endl;
}
bool multi = true;
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      int t = 1;
      if (multi)
            cin >> t;
      while (t--)
      {
            solve();
      }
      return 0;
}
