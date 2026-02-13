#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << " ";
#define int long long int

int dfs(int src , int cl , vector<int>&col , vector<vector<int> >&adj ) {
      col[src]= cl;
      for(int i=1 ;i <=  col.size()-1 ; i ++) {
            if(i == src) continue;
            int to = adj[src][i];

            if( to) {
                  if(col[i] ==0 ) {
                        if(dfs(i,3 - cl , col, adj)== false){
                              return false;
                        }
                  }else if(col[i] != 3 - col[src] ) {
                        return false;
                  }

            }
      }
      return true;
}
void solve(){
      int n , m;
      cin >> n >> m ;
      vector<vector<int>> adj(n+1,vector<int>(n +1 ,1));
      for(int i=0 ; i < m ;i ++){
            int a,b; 
            cin >>a >> b ;
            adj[a][b] = 0;
            adj[b][a] = 0;
      }

      vector<int> col(n+1,0);
      bool ok = true;
      for(int i=1 ;i <= n ;i ++) {
            if(col[i] == 0 ) {

                  if(dfs(i,1,col,adj) == false) {
                        ok = false;
                  }
            }
      }
  
      if(ok){
            cout << "YES" ;
      }else {
            cout << "NO";
      }
      cout << endl;
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
