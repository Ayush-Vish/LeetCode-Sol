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
      vector<int> diff(100001 );
      for(int i=0 ;i < n ;i ++) {
            int l,r;
            cin >> l >> r ;
            l --; r -- ;

            diff[l] +=1;
            diff[r+1] -=1;
      }
      for(int i=1 ;i <= 100000 ;i ++ ) {
            diff[i] += diff[i-1];
      }
      
      int q;
      cin >> q ;
      while(q -- ) {
            int x;
            cin >>x ;
            x -=1;
            cout << diff[x] << endl;
      }
    
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
