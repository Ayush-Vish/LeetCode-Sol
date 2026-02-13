#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 * No as such 
 * 
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n ;
      cin >>n;
      vector<int>a(n);
      for(int i=0 ;i < n; i ++) {
            a[i] = i;
      }

      for(int i=0 ;i < n ;i ++) {
            for(int j=0; j < n ; j ++){
                  cout << (i+j)%n << " ";
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
