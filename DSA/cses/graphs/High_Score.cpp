#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }

struct Edge {
    int u,v,w;
};

void dfs(int i, vector<int>&vis,vector<int>adj[]) {
    vis[i] = 1 ;
    for(auto it : adj[i]) {
        if(!vis[it])
            dfs(it,vis,adj);
    }
}

void solve(){
    int n,m;
    cin >> n >> m ;
    vector<Edge> arr(m );
    vector<int>adj[n],revAdj[n];
    for(int i=0 ;i < m ;i ++) {
        int a,b,c ;
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
        arr[i].u --;
        arr[i].v --;
        arr[i].w  = - arr[i].w;
        adj[arr[i].u].push_back(arr[i].v);
        revAdj[arr[i].v].push_back(arr[i].u);
    }

    vector<int> dist(n, INF);
    dist[0] = 0 ;

    vector<int>vis1(n),vis2(n);
    dfs(0,vis1,adj);
    dfs(n-1,vis2,revAdj);
    for(int i=0 ;i <n;i ++ ) {
        for(auto it : arr ) {
            int u = it.u;
            int v = it.v;
            int w = it.w;
            if(dist[u] == INF) continue;
            if(dist[v]> dist[u] + w ) {
                dist[v ]= dist[u] +w ;
                if(i == n-1 && vis1[v]&& vis2[v])  {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    

    cout << -dist[n-1] << endl; 
    

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
//     cin >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
