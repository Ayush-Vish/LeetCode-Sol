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
      int n ; cin >> n;
      string s;
      cin >>s ;
      int ans =0;
      if(n == 1 ) {
            ans =  s[0] - '0';
      }else{
            for(int i=1 ;i < n-1 ; i ++) {
                  ans += 3 *(s[i] == '1');
            }
            ans += 2*(s[0] =='1' )  + 2 * (s[n-1] == '1'  );
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
