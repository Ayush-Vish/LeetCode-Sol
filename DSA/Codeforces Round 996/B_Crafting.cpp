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
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
void solve(){
      int n ;
      cin >> n;
      vector<int>a(n),b(n);
      takeInput(a,n);
      takeInput(b,n);
      vector<int> v(n);
      int cnt =0 ;

      for(int i=0 ;i < n ;i ++ ) {
            v[i] = a[i] - b[i];
            if(v[i] <0 ) {
                  cnt -= v[i];
            }

      }
      bool ok = true;
      for(int i =0 ;i < n ;i ++ ) {
            if(v[i] <0 && cnt + v[i] >0) {
                  ok = false;

            }
            if(v[i] >=0 && v[i]<cnt ) {
                  ok = false;

            }
      }
      cout << (ok ? "YES" :"NO" ) << endl;
      
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}