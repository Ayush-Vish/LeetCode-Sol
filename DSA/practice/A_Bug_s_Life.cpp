#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> col;

bool dfs(int src, int parent, vector<int> adj[], int n, int m){
      for (auto it : adj[src]){
            int next = col[src] == 1 ? 2 : 1;
            if (it != parent){
                  if (col[it] == 0){
                        col[it] = next;
                        if (dfs(it, src, adj, n, m) == false)
                        {
                              return false;
                        }
                  }
                  else if (col[it] != next){
                        return false;
                  }
            }
      }

      return true;
}

void solve()
{
      int n, m;
      cin >> n >> m;
      vector<int> adj[n + 1];
      for (int i = 1; i <= m; i++)
      {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      col.assign(n + 1, 0);
      bool ok = true;
      for (int i = 1; i <= n; ++i)
      {
            if (col[i] == 0)
            {
                  col[i] = 1;
                  if (!dfs(i, 0, adj, n, m))
                  {
                        ok = false;
                        break;
                  }
            }
      }
      if (!ok)
      {
            cout << "Suspicious bugs found!" << endl;
      }
      else
      {
            cout << "No suspicious bugs found!" << endl;
      }
}
bool multi = true;
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      int t = 1;
      if (multi)
            cin >> t;
      for (int _ = 1; _ <= t; _++)
      {
            cout << "Scenario #" << _ << ":" << endl;
            solve();
      }
      return 0;
}
