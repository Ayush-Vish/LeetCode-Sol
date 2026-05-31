#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int please_hire_me(int Z, int O, int K)
{
      // Use raw array and fill with 0
      int ayush[52][52][2][52];
      fill(&ayush[0][0][0][0], &ayush[0][0][0][0] + sizeof(ayush) / sizeof(int), 0);

      if (Z > 0)
            ayush[1][0][0][1] = 1;
      if (O > 0)
            ayush[0][1][1][1] = 1;

      // Lambda to handle transitions
      auto update = [&](int z, int o, int bit, int len, int val)
      {
            if (bit == 0)
            {
                  // Extend zero sequence
                  if (z + 1 <= Z && len + 1 < K)
                        ayush[z + 1][o][0][len + 1] = (ayush[z + 1][o][0][len + 1] + val) % MOD;
                  // Switch to 1
                  if (o + 1 <= O)
                        ayush[z][o + 1][1][1] = (ayush[z][o + 1][1][1] + val) % MOD;
            }
            else
            {
                  // Extend one sequence
                  if (o + 1 <= O && len + 1 < K)
                        ayush[z][o + 1][1][len + 1] = (ayush[z][o + 1][1][len + 1] + val) % MOD;
                  // Switch to 0
                  if (z + 1 <= Z)
                        ayush[z + 1][o][0][1] = (ayush[z + 1][o][0][1] + val) % MOD;
            }
      };

      for (int z = 0; z <= Z; z++)
      {
            for (int o = 0; o <= O; o++)
            {
                  for (int bit = 0; bit <= 1; bit++)
                  {
                        for (int len = 1; len < K; len++)
                        {
                              int val = ayush[z][o][bit][len];
                              if (val == 0)
                                    continue;
                              update(z, o, bit, len, val);
                        }
                  }
            }
      }

      int res = 0;
      int b = 0;
      while (b <= 1)
      {
            int l = 1;
            while (l < K)
            {
                  res = (res + ayush[Z][O][b][l]) % MOD;
                  l++;
            }
            b++;
      }

      return res;
}

int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            int z, o, k;
            cin >> z >> o >> k;
            cout << please_hire_me(z, o, k) << endl;
      }
}
