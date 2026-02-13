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
vector<int>c,vis;
int sz = 0 ;
void dfs1(int src,vector<pair<int,int>>adj[]) {
    sz ++;
    vis[src] = 1;
    for(auto [it,_] : adj[src])  {
        if(!vis[it]) {
            dfs1(it,adj);
        }
    }
}


void dfs2(int src ,vector<pair<int,int>>adj[], int curr ){
    vis[src] =1 ;
    sz++;
    for(auto [it,mask] : adj[src]) {
        if ( (mask & curr) != mask ) {
            continue;
        }
        if(!vis[it]) {
            dfs2(it,adj,curr);
        }

    }
}

void solve(){
    int n,m,k;
    cin >> n >> m >>  k ;
    c.resize(k+1);
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<k;i++) cin >> c[i];
    for(int i=0; i < m;i ++) {
        int a,b,l;
        cin >> a >> b>> l;
        int mask =0;

        for(int j=0 ; j < l;j ++) {
            int ind;cin >>ind;
            mask |= (1LL << (ind-1)); // Ceates a set bit eith only that Piostion 
        }
        adj[b].push_back({a,mask});

        adj[a].push_back({b,mask});
    }
    vis.assign(n+1,0);
    dfs1(1,adj);
    if(sz != n ) {
        cout << -1 << endl;
        return;
    }

    int largest = (1LL <<k)-1;
    int ans =0;

    for(int i=k-1; i>=0; i --) {
        sz=0;vis.assign(n+1,0);
        dfs2(1,adj , largest^ (1LL << i ));
        if(sz != n){
            ans += c[i];
        }else {
            largest= largest ^ ( 1LL << i );
        }
    }
    cout << ans <<endl;
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
