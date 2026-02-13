#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * I am thinking like we can just 
 * add n/2 + from (n- n/2 )/2
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >>n;
      if(n ==1) {
            cout << 1 << endl;
            return;
      }
      if(n % 2 ==0 ) {
            cout <<n/2 +( ((n-n/2)+1)/2) << endl;
      }else{
            cout << n/2 +1  << endl;
      }
    
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
