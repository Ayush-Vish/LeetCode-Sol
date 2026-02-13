#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x ;
#define int long long int
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs1(int i, int j , int depth , int &temp, vector<vector<int>> &vis, pair<int,int>&ans , vector<vector<char>> &v ) {
      vis[i][j] = 1;
      if(depth >= temp) {
            temp = depth;
            ans = {i,j};
      }

      for(int k =0 ;  k< 4 ;k ++) {
            int nx = dx[k] + i ;
            int ny = dy[k] + j ;
            if(nx >=0 && ny >=0 && nx< v.size() && ny< v[0].size() && vis[nx][ny] == 0 && v[nx][ny] == '.'){
                  dfs1(nx ,ny , depth +1, temp  , vis, ans , v );

            }
      }
}

void dfs2(int i, int j , int depth , int &temp, vector<vector<char>> &v, vector<vector<int>> &vis ) {
      vis[i][j] = 1;
      if(depth > temp) {
            temp = depth;
      }

      for(int k =0 ;  k< 4 ;k ++) {
            int nx = dx[k] + i ;
            int ny = dy[k] + j ;
            if(nx >=0 && ny >=0 && nx< v.size() && ny< v[0].size() && vis[nx][ny] == 0 && v[nx][ny] == '.'){
                  dfs2(nx ,ny , depth +1, temp  , v ,vis  );

            }
      }
}

void solve(){
      int n ,m ;
      cin >> m >> n;
      vector<vector<char>> v(n,vector<char>(m));
      for(int i=0 ;i < n ;i ++) {
            for(int j=0 ; j < m ;j ++) {
                  cin >> v[i][j];
            }
      }

      pair<int,int> last;
      vector<vector<int>> vis(n,vector<int>(m, 0 ));
      int temp =0;
      for(int i=0 ; i < n ; i ++) {
            for(int j=0 ; j < m ; j ++) {
                  if(v[i][j] == '.'){

                        dfs1(i,j ,0,temp,vis,last,v);
                        break;
                  }     
            }
      }


      int depth =0;
      vis.assign(n,vector<int>(m,0));
      dfs2(last.first,last.second, 0, depth ,v,vis);
      cout << "Maximum rope length is "  <<  depth << "." << endl;
    
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
