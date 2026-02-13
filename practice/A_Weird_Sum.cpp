#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
int n ,m;

void solve(){
      cin >> n >>m ;
      map<int,set<int>> mpp;
      
      vector<vector<int>> a(n,vector<int>(m,0));
      for(int i=0 ;i <  n ;i ++) {
            for(int j=0 ; j < m ;j ++) {
                  cin >> a[i][j];
            }
      }

      
    
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
