#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  *   4
      3
      1 3 6
      3
      1 3 5
      3
      1 3 4
      4
      1 2 3 7
      Output
      1 3 2
      2 3 2
      3 2 2
      4 4 4 1


  */

void solve(){
      int n;
      cin >> n ;
      vector<int> a(n);
      for(int i=0 ;i < n ;i ++) cin >> a[i];

      vector<int>ans(n);
      int curr =n ;
      ans[0] = curr;
      curr -- ;
      

      for(int i=1 ;i < n;i ++) {
            int temp = a[i] - a[i-1] ;
            if((i+1)- temp  == 0 ) {
                  ans[i] = curr;
                  curr -- ;

            }else{
                  ans[i] =ans[(i+1)-temp -1 ];
            }
      }
      for(auto it : ans ) cout << it << " ";
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
