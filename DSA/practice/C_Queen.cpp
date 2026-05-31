#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      vector<int> par(n+1),rmv(n+1,1),c(n+1);
      for(int i=1 ;i <= n ;i ++) {
            cin >> par[i] >> c[i];
            if(c[i] == 0) {
                  rmv[i] = 0;
            }
      }
      for(int i=1 ;i <= n ;i ++) {
            if(c[i] == 0 && par[i] != -1) {
                  rmv[par[i]] = 0 ;
            }
      }
      int cnt =1 ;
      for(int i=1 ;i <=n ;i ++) {
            if(rmv[i]) cout << i << " ",cnt =0 ;
      }
      if(cnt){
            cout << -1 ;
      }
      cout << endl;


    
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
