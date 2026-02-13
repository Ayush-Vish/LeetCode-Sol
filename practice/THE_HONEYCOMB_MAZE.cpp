#include <bits/stdc++.h>
using namespace std;
#define int long long int
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool dfs(int x, int y ,int px , int py , vector<vector<char>> &v , int k, int n, int m , vector<vector<int>> &vis) {
      
      if(x == px && y == py && k <=0 ) {
            return true;
      }
      
      vis[x][y] =1;

      for(int k=0 ; k < 4 ;k ++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >=0 && ny >=0 && nx < n && ny < m && v[nx][ny] != '*' && !vis[nx][ny] ) {
                  if(dfs(nx , ny , px , py , v ,k -1  ,n,m,vis)) {
                        return true;
                  }
            }
      }
      vis[x][y] =0;
      return false;
}


void solve()
{
      int n, m;
      cin >> n >> m;
      int k, sx, sy;
      cin >> k >> sx >> sy;
      sx--;
      sy--;

      vector<vector<char>> v(n, vector<char>(m));
      for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                  cin >> v[i][j];

      vector<vector<int>> vis(n,vector<int>(m, 0));
      if(dfs(sx,sx,sx,sy,v,k,n,m, vis) == true){
            cout << "YES";
      }else {
            cout << "NO";
      }


}
bool multi = false;
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      int t = 1;
      if (multi)
            cin >> t;
      while (t--)
      {
            solve();
      }
      return 0;
}
