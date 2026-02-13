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
      int n;
      cin >> n;
      vector<int> ans ;
      for(int i=1 ;i <= 18; i ++) {
            int d =1 ;
            for(int j =0 ; j < i ; j ++ ) {
                  d *=10 ;

            }
            d += 1 ;
            if(n%d  == 0 ) {
                  ans.push_back(n/(d ));
            } 
      }

      sort(ans.begin(),ans.end());
      if(ans.size() ==0 ) {
            cout << 0 << endl;
      }else{

            cout << ans.size() << endl;
            for(auto it: ans ) {
                  cout << it << " ";
            }
            cout << endl;
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
