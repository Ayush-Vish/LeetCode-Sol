#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 * 
 * n/2 + n/3 + n/5  - n/6 - n/15 - n/10 + 
 * for  =0; i < 2 ; i ++  {
 *    for ( int j =0 ; j < 2 ;j ++) {
 *             
 *          
 *    }
 * }
 * 
  * 
 */

 /**
  * Proof:
  * a u b u c =  
  * 
  * 
  *  1 0 1
  *         
  */



void solve(){
      int n,k;
      cin >> n >> k;
      vector<int>a(k);
      for(int i=0 ;i < k ;i ++ ) {
            cin >> a[i];
      }
      int ans =0;
      for(int i = 1; i < (1LL << k); i++){
            int mul  =1 ;
            int cnt =0;
            int temp = i;
            int overflow =0;
            for(int j=0 ; j <k ; j ++ ) {
                  if (i & (1LL << j)) {  
                        cnt++;
                        if(mul > n / a[j]){ 
                              overflow = true;
                              break;
                        }
                        mul *= a[j];
                  }
            }
            if(!overflow){
                  if(cnt % 2) ans += n / mul;
                  else ans -= n / mul;
            }   
            // cout << ans << endl;
      }
      cout << ans << endl;
 
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
