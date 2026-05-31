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
int n,m ;

void solve(){
      cin >> n >> m;
      vector<vector<pll>> adj(n+1 );
      for(int i=0 ;i < m ; i ++ ) {
            int a,b,c;cin >> a >> b >> c ;
            adj[a].push_back({b,c});
            // adj[b].push_back({a,c});
      }
      vector<int> dis (n +1 , INF);
      dis[1] = 0 ;

      priority_queue<pll,vector<pll>,greater<pll>> pq ;
      pq.push({0,1});// O(n + m )*log(n)

      while(!pq.empty()) {
            auto top = pq.top();pq.pop();
            int from = top.second;
            int fromDis = top.first;
            if(fromDis > dis[from]) continue;
            for(auto it :adj[from] ) {
                  int to = it.first;
                  int toDis = it.second;
                  if(dis[to] > dis[from] +toDis) {
                        dis[to] = dis[from] + toDis;
                        pq.push({dis[to] , to}); 
                  }
                  
            }
      }
      for(int i=1 ;i <= n ;i ++  ) {
            cout << dis[i] << " ";
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
