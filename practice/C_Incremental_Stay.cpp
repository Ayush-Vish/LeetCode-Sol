#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * k =1 
 * Simply 
 * sum for all i's => a[i] - a[i-1]
 * 
 * k=2 
 *  a[i+3] - a[i] + a[i+2] - a[i+1] for all i from 0 to n -1 ;
 * 
 * Brute force Will Take me 
 *    n * n 
 *    
 * - can I genrarlize this 
 *    if I have a len n 
 *    then for some random k. 
 *    
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >> n ;
      vector<int>a(2*n);
      vector<int>ans(n+1);

      for(int i=0 ;i <  2*n ;i ++) {
            cin >> a[i];
      }

      for(int i=0; i < n ;i ++) {
            ans[1]  += a[2*i+1] - a[2*i];
      }
      if(n > 1 ) {

            ans[2]  = (a[2*n-1] + a[2*n-2]) - (a[0] + a[1]);
            for(int i=1;i < n-1 ;i ++) {
                  ans[2] += a[2*i] - a[2*i+1];
            }
      }
      for(int k=3 ; k <=n ; k ++) {
            ans[k] = ans[k-2] + 2 * (a[2*n-k+1] - a[k-2]);
      }

      for(int i=1;i<=n;i ++) {
            cout << ans[i] << " " ;
      }
      cout << endl;

    
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
