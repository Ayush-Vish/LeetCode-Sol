#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
map<int,int> mpp1,vis;

const int MAXX = 1e5 + 1;
vector<int> adj[MAXX];
void dfs(int src , int col ) {
      mpp1[src] = col;
      for(auto it : adj[src]) {
            if(vis[it] == 0 ) {
                  vis[it]=1;
                  dfs(it,3-mpp1[src]);
            }
      }
}
void solve(){
      int n ;
      cin >> n ;
      for(int i=0; i < n-1; i ++) {
            int a,b;
            cin >>a >>b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      vis[1]= 1;
      dfs(1,1);
      int two=0,one=0;
      for(auto it : mpp1){
            if(it.second == 1 ) one ++;
            else two ++; 
      }
      int ans=0;
      for(int i=1; i<=n ;i ++) {
            int col = mpp1[i];
            if(col == 1 ) {
                  int ns = adj[i].size();
                  ans += (two -ns );
            }else if(col ==2 ) {
                  int ns = adj[i].size();
                  ans += (one -ns );
            }
      }
      cout << ans/2 << endl;
      
    
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
