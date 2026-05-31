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

int dfs(int i, int j , vector<vector<char>>&g ) {
      int ans =0;

      g[i][j] = 'v';
      for(int k =0 ; k < 4 ; k ++ ) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >=0 && ny >= 0 && nx <g.size()&& ny < g[0].size() && g[nx][ny] != 'v' && g[nx][ny] == '.' ) {
                  ans += dfs(nx ,ny , g );

            }
      }
      return ans ;
}

void solve(){
      int n ,m ;
      cin >> n >> m ;
      vector<vector<char>> g(n , vector<char>(m));
      for(int i=0 ;i < n ;i ++ ) {
            for(int j=0 ; j < m ; j ++ ) {
                  cin >> g[i][j];
            }
      }
      int ans =0 ;
      for(int i=0 ;i < n; i ++ ) {
            for(int j =0 ; j < m  ;j ++ ){
                  if(g[i][j] == '.' && g[i][j] != 'v'){
                        ans ++ ;
                        dfs(i,j,g);
                  }
            }
      }
      cout << ans << endl;
     
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
