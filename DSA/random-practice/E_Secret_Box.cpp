#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
void solve() {
    int x, y, z, vol;
    cin >> x >> y >> z >> vol;
    int ans = 0;    
    for(int i =1 ;i <= x ;i ++ ) {
        for(int j =1 ;j <= y ;j ++ ) {
            if(vol %(i*j)   ) continue;
            int  l=     vol /(i*j);
            if(l > z) continue; 
            int v1=  x-i+1;
            int v2=  y-j+1;
            int v3=  z-l+1;
            ans = max(ans, (v1%mod*v2%mod*v3%mod) %mod  );
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 