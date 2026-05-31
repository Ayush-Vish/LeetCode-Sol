#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * go  to the node with max childrens =>  maxinode
 * run a dfs of max h to end node.
 * from endNode -> MaxiNode cnt all the branches.
 * 
 * so ans =  cnt +1 ;
 * 
 * But this is Complicated :
 *    soln are always Simple.
 *    so if we merge a path it shpuld be from a rooted node to a leaf: 
 *    So for k leaf in wholle tree we need k oprations to merge - no of leaf which the rooted node has,
 *    ans we nedd to minimize it for all node. 
 */   


 /**
  * Proof:
  * 
  */


void solve(){
      int n;
      cin >> n ;
      vector<int>adj[n+1];
      for(int i=0 ;i < n -1  ;i ++) {
            int a,b;
            cin >>a >> b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      int leaf =0 ;
      vector<int>cnt(n+1);
      for(int i=1 ;i<=n ;i ++) {
            if(adj[i].size() ==1 ) leaf ++;
            else{
                  for(auto it  : adj[i]) {
                       
                        if(adj[it].size() ==1 ) {
                              cnt[i] ++;
                        }
                        
                  }
            }
      }

      int mini = leaf;
      for(int i =1 ;i <=n ;i ++) {
            mini = min(mini, leaf - cnt[i]);
      }
      cout << (mini == n ? 0 : mini) << endl;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
