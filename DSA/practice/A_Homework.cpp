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
      int n ,m ;
      cin >> n ;
      string s, t ;
      cin >> s ;
      cin >> m ;
      cin >> t ;
      string k;
      cin >> k;
      string temp1="",temp2 ="";
      for(int i= 0 ;i < k.size() ; i ++) {
            if(k[i] == 'V') temp1 += t[i];
            else temp2 += t[i];
      }
      reverse(temp1.begin(),temp1.end());
      cout << temp1 + s  + temp2 << endl;
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
