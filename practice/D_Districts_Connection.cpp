#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

vector<pair<int, int>> edges; // store the valid roads
vector<int> ans;

void dfs(int src, vector<int>& vis, vector<int>& a, int n) {
    vis[src] = 1;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && a[i] != a[src]) {
            edges.emplace_back(src + 1, i + 1); // store 1-based index edge
            dfs(i, vis, a, n);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mpp;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mpp[a[i]]++;
        mx = max(mx, mpp[a[i]]);
    }

    if (mx == n) {
        // All values are same → no connection possible
        cout << "NO\n";
        return;
    }

    vector<int> vis(n, 0);
    edges.clear();

    dfs(0, vis, a, n);

    // After DFS, if we have less than n - 1 edges → graph is not connected
    if ((int)edges.size() < n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto& [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
