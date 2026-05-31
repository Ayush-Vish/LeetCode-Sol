#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
      let dp[i][w] states -> the cost at ith with wieght w 
      dp[i][j] = max(dp[i-1][j] , if(W - wt[i] > 0 ) dp[i-1][j - wt[i] ] ))
      

      this is the same as prev one 
      but we need to optimise it and |wt| ~ 1e9
      this shit I dont know ->
      prev => we want the max value while carrying weight W 
      curr => we want the min wt I need to carry to obtain a value v 

      
 */



 /**
  * Proof:
  * 
  */

void solve(){
      int n,w ;
      cin >> n >>w  ;
      vector<int>wt(n),a(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> wt[i] >> a[i];
      }
      vector<int> dp  (w +1 , 0), prev(w+1,0 );
     
      int ans =0 ;

      for(int i=1 ;i <=n; i ++) {
            for(int j=0 ; j<= w ; j ++) {
                  dp[j] = max(
                        prev[j],
                        j-wt[i-1] >=0 ? prev[j-wt[i -1 ]] + a[i -1 ]: INT_MIN
                  );

            }
            prev = dp;
      }
      cout << prev [w] << endl;
    
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
