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

void dfs(int src , vector<int>adj[] , vector<int>&vis ) {
      vis[src ] = 1 ;
      for(auto it : adj[src] ){
            if(vis[it] == 0 ) {

                  dfs(it , adj , vis );
            } 
      }
}

void solve(){
      int city , roads;
      cin >> city >> roads;
      vector<int> adj[city +1 ];
      for(int  i=0 ;i < roads ; i ++ ) {
            int u,v;
            cin >> u >> v ;

            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      vector<int> compo;
      vector<int> vis(city +1 );
      for(int i=1 ;i <= city ; i ++ ) {
            if(!vis[i]  ) {
                  compo.push_back(i);
                  dfs(i,adj,vis);
            }
      }
      cout << compo.size() -1  << endl;
      for(int i=0 ; i < compo.size() - 1 ; i ++ ) {
            cout << compo[i] << " " << compo[i+1] << endl; 
      }
      
     
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
