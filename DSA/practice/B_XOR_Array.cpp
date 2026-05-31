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
   int n,l,r;
   cin >> n >>l >>r;
   vector<int>a(n+1);
   for(int i=0 ;i <=n;i ++) {
    a[i]=i;
   }
   a[r]=l-1;
   vector<int>b(n+1);
   for(int i=1;i<=n;i++){
        b[i]=a[i]^a[i-1];
   }

   for(int i=1;i<=n;i++)cout<<b[i]<<" ";

   cout << endl;
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
