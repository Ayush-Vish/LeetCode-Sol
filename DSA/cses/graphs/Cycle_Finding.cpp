#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

int n, m;
vector<tuple<int, int, int>> edges;

void solve() {
    cin >> n >> m;
    edges.clear();
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges.emplace_back(a, b, c);
    }

    vector<int> dist(n, 0);
    vector<int> parent(n, -1);
    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
              for (int i = 0; i < n; i++) {
            x = parent[x];
        }
        

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());
        for (int v : cycle) cout << v + 1 << " ";
        cout << "\n";
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
