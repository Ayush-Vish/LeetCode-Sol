#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<int> parent;
int f(int node)
{
      if (parent[node] == node)
      {
            return node;
      }

      return parent[node] = f(parent[node]);
}
void solve()
{
      int n;
      cin >> n;

      vector<int> ans;
      vector<pair<int, int>> p;
      int sz = 0;

      for (int i = 0; i < n; i++)
      {
            int a, b;
            cin >> a >> b;

            sz = max({sz, a, b});
            p.push_back({a,b});
      }
      parent.resize(sz + 1);
      for (int i = 1; i <= sz; i++)
      {
            parent[i] = i;
      }
      for (int i = 0; i < n; i++)
      {
            int a = p[i].first;
            int b = p[i].second;
            a = f(a);

            b = f(b);
            if (a != b)
            {
                  parent[a] = b;
                  ans.push_back(i + 1);
            }
      }
      cout << ans.size() << endl;
      for (auto it : ans)
      {
            cout << it << " ";
      }

      cout << endl;
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
      while (t--)
      {
            solve();
      }
      return 0;
}
