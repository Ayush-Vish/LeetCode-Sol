#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >> n ;
      string s ;
      cin >>s ;
      bool ok = true;
      for(int i= 0; i < n -2 ; i ++) {
            if(s[i] == '0' && s[i+1] == '1' && s[i +2 ] == '1') {
                  ok = false;
            }
      }
      if(ok) {
            cout << "YES" << endl;
      }else{
            cout << "NO" << endl;
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
