#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * So the pattern il like 
 *    o2 will only do one operations at max 
 *    Goal is to finfd the op to make a -> 2*x 
 * 
 *    so ans will be 
 *          a..a -> op times , b 
 *    will be reverse if(x > a )
 *    Not Working tho 
 * 
 * 
 *    Now just Sumilate:      
 * 
 * 
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
      int n,k;
      cin >> n >> k ;
      int tot = 1LL << (n+1) ;
      int y = tot - k ;


      vector<int> ans ;

      while( k != y  ) {
            if( k < y ) {
                  y -= k;
                  k = k +k;
                  ans.push_back(1);
            }else{
                  k -= y ;
                  y = y +y; 
                  ans.push_back(2);
            }
      }
      reverse(ans.begin(),ans.end());
      cout << ans.size() << endl;
      for(int i=0 ;i < ans.size(); i ++) {
            cout << ans[i] << " ";
      }      
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
