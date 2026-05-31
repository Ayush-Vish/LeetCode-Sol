#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 * 
 * let 
 *   dp[kind ][i] -> max cute till ith and kind kindth and prev kind != curr Kind.
 *    dp[king]
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >> n;
      vector<int>a(n),b(n),c(n);
      vector<vector<int>> dp(3 ,vector<int>(n , INT_MIN )) ;
      for(int i=0 ;i <n ;i ++) {
            cin >> a[i] >> b[i] >> c[i];
      }
      dp[0][0] = a[0], dp[1][0] = b[0], dp[2][0] = c[0];


      
      for(int i=1 ;i < n ;i ++) {

            for(int j=0; j < 3 ; j ++) {
                  for(int k =0; k < 3 ;k ++) {
                        if(j != k) {
                              dp[k][i] = max(dp[k][i], dp[j][i-1] + (k == 0 ? a[i]: k ==1 ? b[i]:c[i])  ); 
                        }
                  }
            }

      }
      cout << max({dp[0][n-1] , dp[1][n-1], dp[2][n-1]});

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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
