#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
    int n,m,k;
    cin >> n >> m >> k ;
    vector<int>a(n);
    for(int i=0 ;i < n ;i  ++) {
        cin >> a[i];
    }
    if(k >= n ) {
        cout << n << endl;
        return;
    }
    vector<int> v(n-1);
    for(int i=1 ;i <  n ;i ++) {
        v[i-1] = a[i] - a[i-1];
    }
    sort(v.begin(),v.end());
    int ans =0 ;
    for(int i=0 ;i < n-k ;i ++ ) {
        ans += v[i];
    }
    ans += k ;
    cout << ans << endl; 
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
