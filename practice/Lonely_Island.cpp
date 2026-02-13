#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 */

 /**
  * Proof:
  * 
  */
vector<int>prob, ind,oud,vis;
vector<vector<int>> adj;

void dfs(int src ) {
      vis[src] =1 ;
      for(auto it : adj[src]) {
            prob[it] = prob[src] / oud[src];
            if(!vis[it] ) dfs(it);
      }

}


void solve(){
      int n,m,r;
      cin >> n >> m >> r ;
      prob.resize(n+1,1 );
      ind.resize(n+1);
      oud.resize(n+1);
      adj.resize(n+1);
      vis.resize(n+1);
      for(int i=0 ;i < m ;i ++) {
            int a,b;
            cin >> a >> b ;
            adj[a].push_back(b);
            ind[b] ++;
            oud[a] ++;
      }

      dfs(1);

      int ans =0;
      for(auto it : oud){
            cerr << it << " " ;
      }
      cerr << endl;
       for(auto it : prob){
            cerr << it << " " ;
      }
      int index = -1;
      for(int i=1 ;i <= n ;i ++){
            if(prob[i] > ans ) {
                  ans = prob[i];
                  index = i;
            }
      }
      cout << index << endl;
    
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
