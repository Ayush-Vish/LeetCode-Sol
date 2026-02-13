#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<vector<pair<int,int>>> adj;
vector<int> color ,vis;
int maxi = 0 ;
bool ok = false;
void dfs(int src ) {
      vis[src] =1 ;
      for(auto [it,_] : adj[src]) {
            if(vis[it] == 0 ) {
                  dfs(it);
            }else if (vis[it ] == 1 ) {
                 ok = true;
            }
      }
      vis[src] = 2;
}
void dfs2(int src ) {
      vis[src] = 1;
      for(auto [it,id] : adj[src]) {
            if(vis[it] == 0 ) {
                  color[id] =1;
                  dfs2(it);
            }else if(vis[it] == 1) {
                  color[id] =2 ;
            }else {
                  color[id] =1;
            }
      }
      vis[src] =2;
}
void solve(){

      int n,m;
      cin >> n >> m ;
      adj.resize(n+1);
      color.resize(m+1,0);
      vis.resize(n+1);
      for(int i=1; i<=m;  i ++) {
            int a,b; 
            cin >>a >> b ;
            adj[a].push_back({b,i});
      }
      for(int i=1 ;i <= n ;i ++) {
            if(vis[i] == 0) dfs(i);
      }

      if(!ok) {
            cout << 1 << endl;
            for(int i=1; i<=m ;i ++) {
                  cout << 1 <<" ";
            }

      }else {
            vis.assign(n+1,0);
            for(int i=1 ;i <= n ;i ++) {
                  if(vis[i] == 0 ) dfs2(i);
            }
            cout << 2 << endl;
            for(int i=1 ; i<=m ; i++) {
                  cout << color[i] << " ";
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
