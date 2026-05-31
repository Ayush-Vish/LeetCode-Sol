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
      int n,m;
      cin >>  n >>m ;
      vector<int> a(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }

      sort(a.begin(),a.end() , greater<int>());
      int ans =0;
      
      for(int i=0;i < min(n,m); i ++ )  {
            int rem = m-i;
            ans += (a[i]*rem);
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
