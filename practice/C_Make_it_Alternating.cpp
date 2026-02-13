#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
const int MOD = 998'244'353;
void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}
void solve()
{
      string s;

      cin >> s;
      int res = 1;
      int k = s.size();
      int n = s.size();
      for (int l = 0; l < n;)
      {
            int r = l + 1;
            while (r < n && s[l] == s[r])
                  ++r;
            upd(res, r - l);
            --k;
            l = r;
      }

      for (int i = 1; i <= k; ++i)
            upd(res, i);
      cout << k << ' ' << res << endl;
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
