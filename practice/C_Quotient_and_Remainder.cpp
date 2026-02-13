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
   int n,k;
   cin >> n >>k ;
   vector<int>q(n);
   for(int i=0;i<n;i++) cin >> q[i];
    vector<int>r(n);
    for(int i=0;i<n;i++)cin >> r[i];
    sort(q.begin(),q.end());
    sort(r.begin(),r.end());
    int i=0,j=n-1;
    int ans=0;
    while(i<n && j>=0){
        if(q[i]*(r[j]+1) +r[j]<=k){
            ans++;
            i++;
            j--;
        }else{
            j--;
        }
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
