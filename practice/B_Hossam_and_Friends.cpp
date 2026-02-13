#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * we will  Slide variable Window such that if one pair is there then we will shrink the window else we will 
 * expand 
 * how will I will find the let say I have 
 * we can maintain the set and we will delete the set elements from the set when we expand the window
 * 
 * Above one will not Work:
 * we can simpl find the minimum non-friend for each index i 
 * this is how we will find the feasible len in constant time.
 *  then we will do 
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n , m ;
      cin >> n >> m ;

      vector<int> f(n+1,n);
      f[0]=0;
      for(int i=1 ;i <=m;i ++) {
            int a ,b;
            cin >>a >>b ;
            if(a >b ) swap(a,b);
            f[a] = min(f[a],b -1 );
      }

      for(int i=n-1 ; i ; i  --) {
        f[i] = min(f[i],f[i+1]);
      }
      int ans =n ;
      for(int i=0 ; i < n;i ++){
        ans +=  (f[i]-i);
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
