#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;
      cin >> n ;
        vector<int>a(n+1);
        for(int i=1;i <= n ;i ++) {
            cin >>a[i];
        }
        int ans =0 ;
        vector<int> v;
        for(int i=1 ;i <=n ;i ++ ) {
            if(a[i] >= i ) continue;
            ans += lower_bound(v.begin(),v.end(),a[i]) - v.begin();
            v.push_back(i);
        }
        cout << ans << '\n';
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
