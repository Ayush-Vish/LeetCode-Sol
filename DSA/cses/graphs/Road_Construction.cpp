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
vector<int> __;
vector<vector<int>> __2d;
class Ds  {
      public:
      vector<int> size,parent;

      Ds(int n) {
            size.resize(n,1);
            parent.resize(n);
            for(int i=0 ; i < n ;i ++ ) {
                  parent[i] = i ;
            }      
      }
      
      int findupp(int a) {
            if(a == parent[a]) return a ;
            parent[a] =findupp(parent[a]) ;
            return parent[a];
      }
      void ubySize(int u,int v ) {
            int ua= findupp(u);
            int va= findupp(v);
            if(size[ua] > size[va]) {
                  parent[va] = ua;
                  size[ua] += size[va];
            } else {
                  parent[ua] = va;
                  size[va] += size[ua];
            }

      }
};

void solve(){
      int n,m;
      cin >> n >> m ;
      Ds d (n);
      int maxi = 1 ;
      int compo = n ;


      for(int i=0 ;i < m ;i ++ ) {
            int a ,b;
            cin >> a >> b;
            a -- ,b -- ;
            if(d.findupp(a) != d.findupp(b)) {
                  compo -- ;
                  d.ubySize(a,b);
                  maxi = max(maxi, d.size[d.findupp(a)]);
            }
            cout << compo << " "<< maxi <<endl; 

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
