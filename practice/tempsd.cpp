#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MODULOOOOO = 1e9 + 7;

ll SubsequenceGCD(ll L, ll R)
{
      // Precompute GCDs for digits 1 to 9
      vector<vector<int>> ayush(10, vector<int>(10));
      int i = 1;
      int j = 1;
      while (i < 10)
      {
            j = 0;
            while (j < 10)
            {
                  ayush[i][j] = __gcd(i, j);
                  j++;
            }
            i++;
      }

      int var = false;
      for(int i=1 ; i < 10 ; i ++ ) {
            var |= i ;
      }
      if(var == false) {
            return 0LL;
      }

      // Main DP function
      auto sundar_pichai = [&](ll X) -> ll
      {
            if (X < 0)
                  return 0;
            string mystring = to_string(X);
            int n = mystring.size();

            ll dp[20][10][2][2];
            fill(&dp[0][0][0][0], &dp[0][0][0][0] + sizeof(dp) / sizeof(ll), -1);

            function<ll(int, int, int, int)> get_answer = [&](int pos, int g, int z, int tight) -> ll
            {
                  if (pos == n)
                  {
                        if (g == 0 || z)
                        {
                              return 0;
                        }
                        return g;
                  }

                  ll &res = dp[pos][g][z][tight];
                  if (res != -1)
                        return res;

                  ll ans = 0;
                  int limit;
                  if (tight)
                  {
                        limit = mystring[pos] - '0';
                  }
                  else
                  {
                        limit = 9;
                  }

                  for (int d = 0; d <= limit; ++d)
                  {
                        int new_tight = tight && (d == limit);
                        int new_g = g, new_z = z;

                        auto aditi = [&]()
                        {
                              if (g == 0)
                              {
                                    if (d > 0)
                                          new_g = d;
                              }
                              else
                              {
                                    if (d == 0)
                                          new_z = 1;
                                    else
                                          new_g = ayush[g][d];
                              }
                        };

                        aditi();
                        ans = (ans + get_answer(pos + 1, new_g, new_z, new_tight)) % MODULOOOOO;
                  }

                  return res = ans;
            };

            return get_answer(0, 0, 0, 1);
      };

      ll ans = (sundar_pichai(R) - sundar_pichai(L - 1)) % MODULOOOOO;
      if (ans < 0)
            ans += MODULOOOOO;
      return ans;
}

int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            int l, r;
            cin >> l >> r;
            cout << SubsequenceGCD(l, r) << '\n';
      }
}
