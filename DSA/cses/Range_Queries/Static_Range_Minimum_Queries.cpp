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

int _;
vector<int> __, v ,pre;
vector<vector<int>> __2d;

void solve(){
     int n,m;
     cin >> n >> m;
     v.resize(n);
     pre.resize(n);
     int log = log2(n) +1 ;
     vector<vector<int>> a(n,vector<int>(log));
     for(int i=0 ;i < n ;i ++  ){
      cin >> v[i];
      a[i][0] = v[i];

     }
     /**
      * let say we want to maker the table 
      * 
      * [0,1,2,3,4,5,6,7,8] 
      * 
      */
     for(int k=1  ; k < log ;k ++ ){
      for(int i=0 ;i + (1 << k) - 1  < n ; i++ ){
            a[i][k] = min(a[i][k-1],a[ i + (1 << (k-1))][k-1]);
      }

     }




     for(_=0; _<m ;_++){
      int x,y ;
      cin >> x >> y ;
      x -- ;
      y -- ;
      int len = y -x +1 ;
      int k =0 ;
      while((1 << (k+1 ) )<= len ) {
            k ++ ;

      }
      cout << min(a[x][k],a[y  - (1 << k ) +1 ][k]);
      cout << "\n"; 
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
