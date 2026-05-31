#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * dp[i] -> min cost for Reacding the ith block 
 * so dp[i ] = min(dp[i-1] + cos, dp[i-2] + cost );
 * 
 */

 /**
  * Proof:
  * 
  */



void solve(){
      int n ;
      cin >> n ;
      vector<int>dp(n+1, INT_MAX), a(n);
      for(int i=0 ;i < n  ;i ++) {
            cin >> a[i];
      }

      dp[0] = 0 ;
      for(int i=1 ;i< n ;i ++) {
            dp[i] = min(
                  dp[i-1] + abs(a[i-1] -a[i]),
                  i > 1 ? dp[i-2] + abs(a[i-2] - a[i]) : INT_MAX
            );
      }
      cout << dp[n -1 ] << endl;
      
    
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
