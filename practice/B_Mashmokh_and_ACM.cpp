#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, k;
vector<vector<int>> dp;
int f(int len, int last){
      if (len == k)
            return 1;
      if (dp[len][last] != -1)
            return dp[len][last];
      int res = 0;
      for (int next = last; next <= n; next += last){
            res = (res + f(len + 1, next)) % MOD;
      }
      return dp[len][last] = res;
}
int main(){
      cin >> n >> k;
      dp.assign(k + 1, vector<int>(n + 1, -1));
      int total = 0;
      for (int start = 1; start <= n; ++start){total = (total + f(1, start)) % MOD;} // n 
      cout << total << endl;
      return 0;
}
