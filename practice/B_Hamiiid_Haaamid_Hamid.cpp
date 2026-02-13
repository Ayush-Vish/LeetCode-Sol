#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * I am thinking to take the side which have the least no   of walls 
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n,x;
      cin >> n >> x ;
      string s ;
      cin >>s ;
      int l=0,r=0;
      bool ok=0;
      for(int i=0 ;i < s.size(); i ++) {
            if(i+1 == x){
                  ok=1;
            }
            if(ok==0) {
                  if(s[i] == '#') l ++;
            }else{
                  if(s[i] == '#') r ++;
            }
      }
      cout  << min(l+1,r+1)  << endl;
    
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
