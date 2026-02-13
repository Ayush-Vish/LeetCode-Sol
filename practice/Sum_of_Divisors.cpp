#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * for 1 = >1 -> 1 
 *  2 => 1,2 => 3 
 * 3 => 1, 3  => 4 
 * 
 * 4 => 1,2,4 => 7  
 *  5 => 1,5  => 6 
 * Total => 
 *  6 => 1,2,3,6 0
 * 
 * So I have a
 *    for i =2 ; i < sqrt(n) ; i ++
 *          while(n )
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int ans =0 ;
      int n ;
      cin >> n;
      
      for(int i=1 ;i <=n ;i ++) {
            int temp =0 ;
            
            for(int j=1 ; j <= n ;j ++) {
                  if(i % j ==0 ) {
                        temp += j;
                  }
            }
            ans += temp;
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
