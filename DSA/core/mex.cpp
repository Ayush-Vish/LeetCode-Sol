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

class Mex { 
      private:
      // freq 
      map<int,int> mpp ;
      // missing no in array  -> candidates of MEX 
      set<int> st ;
      // smalllest missing no will be *st.begin();
      vector<int> arr ;
      Mex( vector<int>a ) {
            for(int i=0; i <=a.size();i++) {
                  st.insert(i);
            }
            for(auto it :a ) {
                  mpp[it] ++;
                  st.erase(it);
            }
      }
      protected:
      int mex() {
            return *st.begin();
      }
      void update(int idx ,int val ) {
            mpp[arr[idx]] --;
            if(mpp[arr[idx]] ==0 ) {
                  st.insert(arr[idx]);
            }
            arr[idx] = val;
            ++mpp[val];
            st.erase(val);
      }

};


void solve(){
      vector<int>a = {0,1,2,4,5};
      set<int> st(a.begin(),a.end());
      int res =0 ;
      while(st.count(res)) {
            res ++ ;

      }
      cout << res << endl;

      
     
}
bool multi = 0;
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
