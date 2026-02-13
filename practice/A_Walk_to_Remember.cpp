#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<int> vis;

void dfs(int src, vector<int>adj[],stack<int>&st) {
      vis[src] =1;
      for(auto it : adj[src]) {
            if(!vis[it]) {
                  dfs(it,adj,st);
            }
      }
      st.push(src);
}

void dfs2(int src, vector<int> &temp, vector<int>adj[]) {
      vis[src ] =1;
      temp.push_back(src);
      for(auto it : adj[src]) {
            if(!vis[it]) {
                  dfs2(it,temp,adj);
            }
      }
}
void solve(){
      int n ,m ;
      cin >> n >> m ;
      vector<int> adj[n+1];
      for(int i=0; i < m ;i ++) {
            int a,b;
            cin >> a >> b ;
            adj[a].push_back(b);
      }
      vis.resize(n+1);

      stack<int> st;
      for(int i=1 ;i <= n ;i ++) {
            if(!vis[i])
                  dfs(i,adj,st);
      }
      fill(vis.begin(), vis.end(), 0);

      vector<int> rev[n+1];
      for(int i=1; i<=n ; i ++) {
            for(auto it : adj[i]){
                  rev[it].push_back(i);
            }
      }
      vector<int> ok(n+1);
      for(; !st.empty() ;) {
            int i  = st.top();
            st.pop();
            if(!vis[i]){
                  vector<int> ans;
                  dfs2(i,ans,rev);
                  if(ans.size() > 1) {
                        for(auto it : ans){
                              ok[it] =1;
                        }
                  }
            }
      }

      for(int i=1 ;i <=n ; i ++) {
            cout << ok[i] << " ";
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
