#include <bits/stdc++.h>
using namespace std;
#define int  int
#define pb push_back
#define pll pair<int, int>
// const int modll = 1e17;
const int mod = 1e9 + 7;
// const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }
// int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return (a/gcd(a,b))*b; }
int modInverse(int a) { return fastPow(a, mod-2); }
int modAdd(int a, int b) { return (a + b) % mod; }
int modSub(int a, int b) { return (a - b + mod) % mod; }
int modMul(int a, int b) { return (1LL * a * b) % mod; }
vector<int> factorial, inverseFactorial;
void precomputeCombi(int n) { factorial.resize(n+1); inverseFactorial.resize(n+1); factorial[0]=1; for(int i=1;i<=n;i++) factorial[i]=modMul(factorial[i-1],i); inverseFactorial[n]=fastPow(factorial[n],mod-2); for(int i=n-1;i>=0;i--) inverseFactorial[i]=modMul(inverseFactorial[i+1],i+1); }
int NCR(int n, int r) { if(r<0||r>n) return 0; return modMul(factorial[n],modMul(inverseFactorial[r],inverseFactorial[n-r])); }
int _,n;
vector<int> __ ,a ,dp ;
vector<vector<int>> __2d;

void solve(){
      cin >> n ;
      a.resize(n );
      dp.assign(5001,INT_MAX);
      queue<int> q ;

      for(int i=0 ;i < n;i ++ ) {
            cin >> a[i];
            dp[a[i]] =0 ;
            q.push(a[i]);
      }

      int g = 0 ;
      for(int i=0 ;i <n ;i ++ ) {
            g = gcd(g,a[i]);
      }
      int cnt= 0 ;
      for(auto it : a) {
            if(it == g )  {
                  cnt ++ ;

            }
      }
      if(cnt > 0  ) {
            cout << n - cnt  << endl;
            return;
      }

      while(q.size()) {
            int top = q.front();
            q.pop();
            for(auto it:  a  ) {
                  int temp = gcd(it,top);
                  if(dp[temp ] == INT_MAX) {
                        dp[temp] = 1 + dp[top];
                        q.push(temp);
                  }                  
            }
      }
      cout << n  +  dp[g] -1  << endl;
    
}
bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
