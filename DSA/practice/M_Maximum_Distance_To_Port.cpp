#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  * 
  */

void solve(){
    int n,m,k;
    cin >> n >> m >> k ;
    vector<int> a(n);
    for(int i=0 ;i < n ;i ++) {
        cin >> a[i];
    }

    vector<int> dist(n,INT_MAX);
    dist[0] =0;
    vector<int>adj[n];
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b ;
        a --, b --;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    vector<int>ans(k,0);
    while(!q.empty() ) {
        auto [node,d] = q.front();
        q.pop();

        for(auto it : adj[node] ) {
            if(d+1 < dist[it]) {
                dist[it] = d+1;
                q.push({it,d+1});

            }
        }
    }
    
    for(int i=0;i < n ;i ++) {
        ans[a[i] -1] = max(ans[a[i]-1], dist[i]);
    }
    for(auto it: ans ) cout << it << " ";
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
