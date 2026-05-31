#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

void solve(){
    int n;
    cin >> n ;
    int a[n];
    for(int i=0 ;i < n;i ++) {
        cin >> a[i];
    }
    int pre[n],suff[n];
    pre[0] = a[0];
    suff[n-1] = a[n-1];
    for(int i =1 ;i < n ;i ++) {
        pre[i ] =min(a[i],pre[i-1]);
    }
    for(int i=n-2 ;i >=0 ; i --) {
        suff[i] = max(suff[i+1], a[i]);
    }

    for(int i=1;i < n ;i ++) {
        if(pre[i-1] > suff[i]){
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
