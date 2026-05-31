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
vector<vector<int>> adj;

void solve(){
    int n,m;
    cin >> n>> m ;
    adj.resize(n);
    vector<int> in(n);
    for(int i=0 ;i < m ;i ++ ) {
        int a, b; 
        cin >>a >>  b;
        a--;
        b--;
        adj[a].push_back(b);
        in[b] ++ ;

    }
    queue<int> q;
    for(int i=0 ;i <n  ;i ++ ) {
        if(in[i] == 0 ) {
            q.push(i);
        }
    }

    vector<int> ans ;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto it : adj[top]) {
            in[it] -- ;
            if(in[it] == 0 ) {
                q.push(it);

            }
        } 
    }
    if(ans.size() != n )
        cout << "IMPOSSIBLE" ;
    else{
        for(auto it : ans ) {
            cout << it +1  << " " ;
        }
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
