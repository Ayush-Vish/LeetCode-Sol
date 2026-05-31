#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

vector<vector<int>> v,dp;
int f(int i, int j  ) {
      if(j >= v[0].size()) {
            return 0;
      }
      if(dp[i][j] != -1 ) {
            return dp[i][j];
      }
      int take = f(i ==0? 1 : 0 , j +1 ) + v[i][j];
      int nt = f(i, j +1 ) ;
      return dp[i][j]= max(take,nt);
}
void solve(){
      int n ;
      cin >> n ;
      v.resize(2,vector<int>(n));
      dp.resize(2,vector<int>(n, -1));

      for(int i=0 ;i < n ;i ++){
            cin >> v[0][i];
      }

      for(int i=0 ;i < n ;i ++){
            cin >> v[1][i];
      }

      cout << max( f(0,0),  f(1,0)) << endl;

    
}
bool multi = false;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
