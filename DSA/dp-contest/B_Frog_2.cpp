#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 * let 
 *    dp[i] -> min cost at ith index 
 *          dp[i ] = min dp[i], for all j < i dp[j] + cost ;
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n , k ;
      cin >> n >> k  ;
      vector<int>dp(n +1 , INT_MAX), a(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }

      dp[0]= 0;

      for(int i=1 ;i < n ;i ++) {
            for(int j= i ; j >= i-k && j >=0  ;j --) {
                  dp[i] = min(dp[i], 
                        dp[j] + abs(a[i ] - a[j])     
                  );
            }
      }
      cout << dp[n-1] << endl;
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
