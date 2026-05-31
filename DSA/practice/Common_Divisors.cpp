#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * So the gcd will be max if we choose a largerst Prime no.
 * let say we dont have any prime no:     
 *           [2,4,6,8 ]:   
 *           gcd =     
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n;
      cin >> n ;
      vector<int>a(n);
      int maxx = 1e6 +1 ;
      vector<int> cnt( maxx ) ;
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
            cnt[a[i]] ++;
      }

      for(int i= maxx -1 ; i >=1 ; i -- ) {
            int  mul =0 ;
            for(int j=i ; j < maxx ; j+= i  ) {
                  mul += cnt[j];
            }
            if(mul >=2 ) {
                  cout << i<< endl;
                  return;
            }
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
