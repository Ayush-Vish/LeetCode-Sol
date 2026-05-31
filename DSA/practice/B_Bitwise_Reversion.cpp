#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 *    a&b=x 
 *    
      b&c=y
      a&c=z
 *    011000110111010
      000110000010000
      110110111100010
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int x,y,z;
      cin >> x >>  y >>  z;

      long long a = x | z;
      long long b = x | y;
      long long c = y | z;

      if ((a & b) == x && (b & c) == y && (a & c) == z) {
            cout << "YES\n";
      } else {
            cout << "NO\n";
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
