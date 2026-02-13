#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
    int n ;
    cin >> n ;
    vector<int>a(n +1 );
    for(int  i=1;i <=n ;i ++) {
        cin >> a[i];
    }
    vector<int> dp(n+1,1);
    int ans =0 ;

    for(int i=1; i <=n ; i ++) {
        for(int j = 2*i  ; j <= n ; j += i ) {
            if(a[i] < a[j] ) {
                dp[j]  =max(dp[j],dp[i]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
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
