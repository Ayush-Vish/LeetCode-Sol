#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * So like we want to update as well as 
 * Compute sum of all Childs as well.
 *    now if I update a intermediatechild and then compute 
 * I need to update the dp[i] for all the parents for that node
 *  I will take O(n) time and for q queries it will take O(q*n)
 * 
 */

 /**
  * Proof:
  * 
  */

void solve(){
    int n,q;
    cin >> n >> q;

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
