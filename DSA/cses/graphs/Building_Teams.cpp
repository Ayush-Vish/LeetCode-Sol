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

bool bfs(int src , vector<int>&ans , vector<int> adj[] , vector<int> &vis, vector<int>&parent) {
  vis[src ] = 1;
  int curr =1 ;
  ans[src ] = curr;
  queue<int> q ;
  q.push(src);
  while (!q.empty()) {
    int top = q.front(); q.pop();
    for(auto it : adj[top]) {
      if(ans[it] == 0) {
        ans[it] = 3 - ans[top];
        q.push(it);
      }else if (ans[it] == ans[top]  ) {
        return false;

      }
    }
  }
  return true;

  
}

void solve(){
  int n ,m;
  cin >> n >> m;
  vector<int> adj[n +1 ];
  for(int i=0 ;i < m ;i ++ ) {
    int u,v ;
    cin >> u >> v ;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ans(n +1 ),vis(n+1),parent(n + 1, -1 );
  for(int i=1 ; i <=n  ;i ++ ) {
    if(ans[i] == 0 ){
      bool ok = bfs(i, ans , adj ,vis ,parent) ;
      if(!ok) {
        cout <<"IMPOSSIBLE" << endl;
        return ;
      }
    }
  }
  for(int i=1 ;i <=n ;i ++  ){
    cout << ans[i] <<  " ";
  }
  cout << endl;
  // time Complexity = O(n+m)
     
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    // cin >> t;./
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
