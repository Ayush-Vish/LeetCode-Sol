#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long int
void solve(){
    int n ;
    cin >> n ;
    vector<int>a(n),b(n);

    for(int i=0 ;i  < n ;i ++) {
        cin >> a[i];
    }

    for(int j =0 ; j < n; j ++) {
        cin >> b[j];
    }

    int maxi =INT_MIN;
    for(int i=0 ;i < n ;i ++) {
        maxi = max(maxi , a[i]- b[i]);
    }
    vector<int> ans;
    for(int i=0 ;i < n ;i ++) {
        if(a[i] - b[i] == maxi)
            ans.push_back(i +1);
    }
    cout << ans.size() <<endl;
    for(auto it : ans )
        cout << it << " " ;
    cout <<endl;


    
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
