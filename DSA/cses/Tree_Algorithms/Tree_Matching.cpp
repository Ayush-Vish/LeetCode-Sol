// #include <bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define pb push_back
// #define pll pair<int, int>
// const int modll = 1e17;
// const int mod = 1e9 + 7;
// const int INF = 1e18;
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};
// vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
// template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
// template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
// int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }
// int gcd(int a, int b) { if(b==0) return a; return gcd(b, a%b); }
// int lcm(int a, int b) { return (a*b)/gcd(a, b); }
// int modInverse(int a) { return fastPow(a, mod-2); }
// int modAdd(int a, int b) { return (a + b) % mod; }
// int modSub(int a, int b) { return (a - b + mod) % mod; }
 
// int _,n,ans=0;
// vector<int> __,dp;
// vector<vector<int>> __2d,adj;
 
// void dfs(int src , int parent ) {
//       for(auto it : adj[src]) {
//             if(it != parent) {
//                   dfs(it,src);
//                   if(dp[src] == 0 && dp[it] ==0 ){
//                         dp[it] = dp[src] = 1 ;
//                         ans ++ ;
 
//                   }
//             }
//       }
//       // dp[src][want]= ans;
// }
  
// void solve(){
//       cin >> n ;
//       adj.resize(n);
//       dp.resize(n,0);
//       for(int i=0 ; i < n -1;i ++ ) {
//             int a ,b; 
//             cin >>a >>b ;
//             a-- ;
//             b -- ;
//             adj[a].push_back(b);
//             adj[b].push_back(a);
 
//       }
//       dfs(0,-1);
//       cout << ans ;
 
 
     
// }
// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     auto start = chrono::high_resolution_clock::now();
//     int t = 1;
// //     cin >> t;
//     while(t--){
//         solve();
//     }
//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
//     cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
//     return 0;
// }

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
int gcd(int a, int b) { if(b==0) return a; return gcd(b, a%b); }
int lcm(int a, int b) { return (a*b)/gcd(a, b); }
int modInverse(int a) { return fastPow(a, mod-2); }
int modAdd(int a, int b) { return (a + b) % mod; }
int modSub(int a, int b) { return (a - b + mod) % mod; }
 
int _,n,ans=0;
vector<int> __,vis;
vector<vector<int>> __2d,adj,dp;
 
int dfs(int src , int include , int parent  ) {
      if(dp[src][include] != -1 ) return dp[src][include];
      if(!include) {
            int ans =0 ;
            for(auto it : adj[src] ) {
                  if(it != parent) {
                        ans += dfs(it , 1 , src);
                  }
            }
            return dp[src][include] = ans ;
      }else {
            int ans =0 ;
            for(auto it : adj[src]) {
                  if(it != parent ){
                        ans += dfs(it , 1 , src);
                  }
            }
            int res =0 ;
            for(auto it : adj[src]) {
                  if(it != parent) {
                        res = max(res , ans - dp[it][1]+1 + dfs(it,0,src));
                  }
            }
            dp[src][include] = res;
            return res;
      }

}
  
void solve(){
      cin >> n ;
      adj.resize(n);
      vis.resize(n);
      dp.resize(n,vector<int>(2,-1));
      for(int i=0 ; i < n -1;i ++ ) {
            int a ,b; 
            cin >>a >>b ;
            a-- ;
            b -- ;
            adj[a].push_back(b);
            adj[b].push_back(a);
      }
      cout << max(dfs(0,0,-1),dfs(0,1,-1));
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
