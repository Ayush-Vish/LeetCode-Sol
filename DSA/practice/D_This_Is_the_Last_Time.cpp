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
      int n ,k ;
      cin >> n >> k ;
      int m =  n ;

      vector<pair<int,int>> a;
      for(int i=0 ;i < n ;i ++) {
            int x,y,z;
            cin >> x >>  y >> z ;
            a.push_back({x,z});
      }

      sort(a.begin(),a.end() );
      int curr = k ;
      for(int i=0 ;i < n ;i ++) {
            if(curr < a[i].first) break;
            curr = max(curr, a[i].second);
      }
      cout << curr << endl;

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
