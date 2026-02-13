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
   int n ,k;
   cin >> n >> k;
   int a[n];
   for(int i=0 ;i < n ;i ++ ) {
      cin >> a[i];
   } 
   int x= 1;
   int st=  a[k-1];
   sort(a,a + n );
   for(int i=0 ;i < n -1 ;i ++ ) {
      if(a[i] < st ) continue;
      int cost = a[i+1] - a[i];
      x += cost;
      if(x> 1 + a[i]) {
            cout << "NO" << endl;
            return;
      }
}
cout << "YES" << endl;  
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
