#include <bits/stdc++.h>
using namespace std;
#define int long long int
int cnt;
vector<int> B,W;



void dfs(int src , int parent , vector<int> adj[], vector<char> &col ) {
      if(col[src] == 'W'){
            W[src] =1;
      }else {
            B [src] =1;
      }

      for(auto it : adj[src] ) {
            if(it != parent){
                  dfs(it,src, adj , col );
                  W[src] += W[it];
                  B[src] += B[it];
            }
      }
      if(W[src] == B[src]) {
            cnt ++;
      }
}

void solve(){
      int n;
      cin >> n;
      cnt =0 ;

      vector<int> adj[n+1];
      for(int i=1; i <n ;i ++) {
            int a ;
            cin >>a ;
            adj[i+1].push_back(a);
            adj[a].push_back(i+1);
      }
      vector<char> col(n +1 );
      B.assign( n +1,0);
      W.assign( n+1,0 );
      for(int i=0 ; i < n ;i ++){
            char ch;
            cin >> ch;
            col[i+1] = ch; 
      }

      dfs(1,0, adj , col );
      

      cout << cnt << endl;



    
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
