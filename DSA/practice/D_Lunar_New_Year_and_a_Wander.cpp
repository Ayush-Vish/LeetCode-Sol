#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n,m;
      cin >> n >> m ;
      vector<int> adj[n+1];
      for(int i=1;i <=m ;i ++) {
            int a ,  b;
            cin >>a >>b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      vector<int> vis(n+1);
      priority_queue <int,vector<int>,greater<int>> pq;

      pq.push(1);
      vis[1] = 1;

      while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            // if(vis[node] == 1) continue;

            cout << node << " " ;
            for(auto  it : adj[node]) {
                  if(vis[it]==0){
                        vis[it] = 1;
                        pq.push(it);

                  }
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
