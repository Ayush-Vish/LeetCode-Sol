#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n,x,m ;
    cin >> n >> x >> m ;
    
    int l = x , r = x ;
    while(m --) {
        int x, y ;
        cin >> x >> y ;
        
        if(max(l,x) <= min(r,y)) {
            l = min(x, l ) ;
            r = max(y,r);
        }
    }
    cout << r - l +1 << endl;


    
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
