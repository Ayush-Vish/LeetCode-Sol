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

int dfs(int src ,int parent ,  vector<int>adj[] , vector<int>&vis , vector<int>&path , int &start) {
    vis[src] = 1 ;
    path.push_back(src);
    for(auto it : adj[src]) {
        if(!vis[it]  ) {
            if( dfs(it ,src, adj,vis,path ,start)) return true;;
        }else if(it != parent) {
            path.push_back(it);
            start = it;
            return true;
        }
    }
    path.pop_back();
    return false;

}

void solve(){
    int n,m;
    cin >> n >> m ;

    vector<int>adj[n+1];
    for(int i=0; i < m ; i ++ ) {
        int u ,v ;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    vector<int> vis(n+1 ) ;

    for(int i=1 ;i<=n ;i ++ ) {
        if(!vis[i]) {
            vector<int> path;
            int start = 0 ;
            
            if(dfs(i,-1, adj,vis,path,start)) {
                vector<int> ans ;
                for(int j =path.size() -1 ; j >=0; j -- ) {
                    ans.push_back(path[j]);
                    if(path[j] == start && ans.size() > 1 ) {
                        break; 

                    }
                    
                }
                reverse(ans.begin(),ans.end());
                cout << ans.size() << endl;
                for(auto it : ans ) {
                    cout << it << " ";
                }
                return ;

            }
        }
    }
    cout << "IMPOSSIBLE";

     
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
