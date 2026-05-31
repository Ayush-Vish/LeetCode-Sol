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

void solve() {
      int n;
      cin >> n;
  
      vector<int> d(n);
      for (int i = 0; i < n; i ++ )
            cin >> d[i];
  
      vector<pair<int, int>> arr(n);
      for (int i = 0; i < n; i ++ ) 
            cin >> arr[i].first >> arr[i].second;
  
      vector<pair<int, int>> h(n + 1);
      h[0] = {0, 0};  
  
      for (int i = 0; i < n; i ++ ) {
          int mn = h[i].first, mx = h[i].second;
          int nxt_mn, nxt_mx;
  
          if (d[i] == 0) {
              nxt_mn = mn;
              nxt_mx = mx;
          } else if (d[i] == 1) {
              nxt_mn = mn + 1;
              nxt_mx = mx + 1;
          } else {
              nxt_mn = mn;
              nxt_mx = mx + 1;
          }
  
          h[i + 1].first  = max(nxt_mn, arr[ i].first);
          h[i + 1].second = min(nxt_mx, arr[i].second);
  
          if (h[i + 1].first > h[i + 1].second) {
              cout << -1 << endl;
              return;


          }
      }
  
      vector<int> res(n);


       
      int cur = h[n].first;
  
      for (int i = n - 1; i >= 0; i -- ) {
          if (d[i] != -1) {
              res[i] = d[i];
              cur -= d[i];
          } else {
              int h0 = cur;
              if (h0 >= h[i].first && h0 <= h[i].second) {
                  res[i] = 0;
              } else {
                  res[i] = 1;
                  cur -= 1;
              }

              
          }
      }
  
      for (int i = 0; i < n; ++i) {
          cout <<   res[i] <<  " ";
      }
      cout << endl;
  }
  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
