#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 * first we make the pairs of the < and > 
 *          like  <<> - <<><> - <<><><>
 *          then append all the < in the front like << rem times.
 *    if n == 0 then we have a <=< at the back then rem (n-2)* time < at the front
 *    else m == 0 then we have >=> at the back then rem (m-2)*2 times >< at the front.
 *   else   if( n > m )
 *          we have <<> then <<> +<+>  then <<><>+<+ > for m times and remaning n - m times << at the fronte
 *    else 
 *          same but rem m-n <> at the back 
 *                              
 *                            
 */

 /**
  * Proof:
  * 
  */

void solve() {
    int n, m;
    cin >> n >> m;
    string ans;

    if (m == 0) {
          for(int i=0 ;i < n-2 ; i ++) {
            ans += "<<";
        }
        ans += "<=<";
        
    }
    else if (n == 0) {
        // only >  
        // for n = 4 
        //       > < > < >=>
        for(int i=0 ;i < m-2 ; i ++) {
            ans += "><";
        }
        ans += ">=>";
    }
    else {
        for (int i=0 ;i < n-1 ; i ++) {
            ans += "<<";
        }
        ans += "<";
        for(int i=0 ;i < m ;i ++  ) {
            ans += "<>";
        }
    }

    cout << ans << "\n";
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
