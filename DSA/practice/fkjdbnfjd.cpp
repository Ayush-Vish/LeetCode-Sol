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

int  solve(vector<vector<int>>edges, int n ){
    vector<pair<int,int>> adj[n],revAdj[n];
    for(auto it : edges) {
        int a = it[0];
        int b = it[1];
        int c = it[2];
        adj[a].push_back({b,c});
        revAdj[b].push_back({a,c});
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({0,0,0});
    vector<int> dist(n,INT_MAX);
    while(!pq.empty()) {
        auto [curr,u,isUsed] = pq.top();
        pq.pop();
        if(u == n-1) return curr;

        if(isUsed == 0 ) {
            for(auto it : revAdj[u]) {
                int v = it.first;
                int we = it.second;
                if(dist[v] > dist[u]+2*we) {
                    dist[v] = dist[u]+2*we;
                    pq.push({dist[v],v,1});
                }
            }
        }else{
            for(auto it : adj[u]) {
                int v = it.first;
                int we = it.second;
                if(dist[v] > dist[u]+we) {
                    dist[v] = dist[u]+we;
                    pq.push({dist[v],v,isUsed});
                }
            }
        }
    }
    return -1;

    
}
bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        // solve();
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
