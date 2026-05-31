#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
/**
 * vector<int> pre(n-1);
      for(int i=0 ;i <n -1  ;i ++) {
            if(a[i] < a[i+1] || a[i] < b[i+1] || b[i] < b[i+1] || b[i] < a[i+1]) {
                  pre[i] =1;
            }
      }
      for(auto it : pre){
            cout <<  it << " ";
      }
      cout << endl;
      int ans =0;
      for(int i=0,  j=0; i < n-1 ;i ++) {
            if(pre[i] ==1 )  {

                  j = i ;
                  while(a[i] ==1) {
                        i ++;
                  }
                  int len = i-j +1 ;
                  debug(len);
                  ans += (n*(n+1)/2);
            }
      }
      cout << ans << endl;
 */
/**
 * Observations:
 * dp[i][state] => max len of Good Array till len i of type state.
 * 0 => not stated 
 * 1 => prev one was a[i-1];
 * 2 => prev one was b[i-1];
 * 
 * if(type == 0 ) {
 *    dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
 * }else if(type ==1 ) {
 *    if(a[i] > a[i-1]) {
 *          w1 = dp[i-1][1];
 *    }else if(b[i] > b[i-1]){
 *          w2 = dp[i-1][2]
 *   
 *    }
 * 
 *    dp[i][1] =  
 * }
 * 
 *  
 */

 /**
  * Proof:
  * 
  */

 vector<int>a,b;
 vector<vector<int>> dp;
int f(int i , int prev ) {

      if(i ==a.size() ) {
            return 0;
      }

      int ans =0;
      if(dp[i][prev] !=   -1 ) {
            return  dp[i][prev];
      }
      if(prev == 0 ) {
            ans = max(ans, 1 + f(i+1,1));
            ans = max(ans, 1 + f(i+1,2));
      }else if (prev == 1) {
            if(a[i] > a[i-1]) ans = max(ans, 1 + f(i+1,1));
            if(b[i] > a[i-1]) ans = max(ans,1 +  f(i+1,2));
      }else{
            if(a[i] > b[i-1]) ans = max(ans,1 +  f(i+1,1));
            if(b[i] > b[i-1]) ans = max(ans,1 +  f(i+1,2));
      }
      return dp[i][prev]  = ans ;
}

void solve(){
      int n ;
      cin >>n ;
      a.assign(n,0), b.assign(n,0), dp.assign(n,vector<int>(3,-1));
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }
      for(int i=0 ;i < n ;i ++) {cin >> b[i];}

      int ans =0 ;
      for(int i=0 ;i < n ;i ++) {
            ans += f(i,0);
      }
      cout << ans << endl;

    
}
bool multi = true;
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
