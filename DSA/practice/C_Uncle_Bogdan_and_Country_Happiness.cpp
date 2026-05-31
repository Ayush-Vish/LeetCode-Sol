#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<int> p,h;
const int MAXX = 1e5 +1;
vector<int> adj[MAXX];
void solve(){
      int n,m;
      cin >> n >> m ;
      p.resize(n+1);
      h.resize(n+1);

      for(int i=1;i<=n ;i ++) cin >> p[i];
      for(int i=1;i<=n ;i ++) cin >> h[i];
      
      for(int i=0 ; i < n-1; i ++) {
            int a,b;
            cin >>a >>b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }

      


      


    
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
