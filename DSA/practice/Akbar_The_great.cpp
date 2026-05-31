#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n,r,m;
      cin >> n >> r  >> m ;
      vector<int> adj[n+1];

      for(int i=0 ; i < r ;i ++) {
            int a, b; 
            cin >>a  >>b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }

      vector<int> cost(n+1),vis(n+1);
      queue<pair<int,int>> q;
      for(int i=0 ;i < m ;i ++) {
            int a , b; 
            cin >>a >> b ;
            q.push({b ,a });
            vis[a]  =1;
      }


      
      while(!q.empty()) {
            auto [wt, node] = q.front();
            q.pop();

            for(auto it: adj[node]) {
                  if(!vis[it] && wt -1 >=0 ) {
                        q.push({wt -1 , it});
                        vis[it] =1;
                  }
            }
      }

      for(int i=1; i <=n ; i ++) {
            if(vis[i] == 0 ) {
                  cout << "No" << endl;
                  return;
            }
      }
      cout << "Yes" << endl;      
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
