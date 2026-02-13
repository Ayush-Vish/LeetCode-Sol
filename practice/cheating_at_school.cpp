#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      
      int n ;
      cin >> n ;
      vector<int>a(n,0);
      int mini = INT_MAX;
      pair<int,int> ans ;
      for(int i=0, j =0 ;i < n ;i ++) {
            int x;
            cin >>x ;
            a[i] =x ;
            
      }

      for(int i=1;i < n ;i ++) {
            if(mini > (a[i] - a[i-1])) {
                  mini = a[i] - a[i-1];
                  ans = {a[i-1],a[i]};
            }
      }
      
      cout << ans.first << " " << ans.second << endl; 
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
