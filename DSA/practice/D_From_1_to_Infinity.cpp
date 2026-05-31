#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
    
 */

 /**E
  * Proof:
  * 
  */

void solve(){
      int n;
      cin >> n; 
      int d =1 ;
      int m = n ;
      int base = 9;
      while( n - d * 9 > 0  ) {
            n -= d * base;
            base *= 10;
            d ++;
      }
      int index = n %d ;
      int res =( pow(10,(d-1)) + (n-1 ))/d ;
      
      cout << res << endl;


      int ans = res -1;
      
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
