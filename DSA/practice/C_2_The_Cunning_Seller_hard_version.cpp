#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 *
      
 * 
 */

 /**
  * Proof:
  * 
  */




int maxi = 19 ;
vector<int> p,cost;

void solve() {
      int n, k ;
      cin >>  n >> k ;

}
      


bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
      p.resize(maxi +1,1  ), cost.resize(maxi +1 );
      for(int i=1; i <=maxi ; i ++) {
            p[i] = p[i-1]*3;
      }
      for(int i=0;i<=maxi ; i ++) {
            int c = p[i] * 3;
            if (i > 0) c +=  i * p[i - 1];
            cost[i] = c;
      }
      for(auto it : cost) {
            cout << it << " ";
      }
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
