#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n,k;
      cin >> n >> k ;
      
      vector<int> a(n), arr(31);
      int ans=0 ;

      for(int i=0 ;i < n ;i ++){
            cin >> a[i];
            for(int j= 0 ; j < 31 ; j ++) {
                  arr[j] += (a[i] >> j ) &1 ;
            }
      }
      vector<pair<int,int>> v ;
      for(int i=0 ;i < 31 ;i ++) {
            v.push_back({i,arr[i]});
      }
      sort(v.begin(),v.end(),greater<pair<int,int>>());

      for(int i=0 ;i < 31 ;i ++) {
            // cerr << v[i].first << " -> " << v[i].second << 
            if(v[i].second == n ) {
                  ans += (1 << v[i].first);
            }
            else if(n - v[i].second<= k ) {
                  ans += (1 << v[i].first );
                  k = k - (n - v[i].second);
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
