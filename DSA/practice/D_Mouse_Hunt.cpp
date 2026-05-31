#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
int n ;
vector<int> c,parent, vis ;
const int MAXX = 1e5 +1;
vector<vector<int>> adj;

int ans = 0;
void dfs(int src  ) {
      vis[src] =1;
      for(auto it : adj[src]) {
            if(vis[it] == 0 ) {
                  dfs(it);
            }else if(vis[it] == 1 ) {
                  int curr = it;
                  int mini  = c[curr];
                  int x= adj[curr][0];
                  while(x != curr ) {
                        mini = min(c[x],mini);
                        x = adj[x][0];
                  }
                  ans += mini;
            }
      }
      vis[src] = 2;
}




void solve(){
      cin >> n ;
      c.resize(n+1);
      adj.resize(n+1);
      vis.resize(n+1);

      for(int i=1;i<=n ;i ++) cin >>c[i];
      for(int i=1 ;i <=n ;i ++) {
            int a;
            cin >>a ;
            adj[i].push_back(a);
      }
      for(int i=1; i <=  n ;i ++) {
            if(vis[i]  == 0 )  dfs(i);
      }
      cout <<ans << endl;

      


    
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
