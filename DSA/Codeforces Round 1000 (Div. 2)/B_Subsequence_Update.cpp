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
      int n ,l,r;
      cin >> n >> l >> r ;
      vector<int> a(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];

      } 
      vector<int> a1,a2;
      for(int i=0 ;i < r ;i ++ ) {
            a1.push_back(a[i]);
            
      } 
      for(int i= (l-1) ; i<n ; i ++ ){
            a2.push_back(a[i]);
      }
      sort(a1.begin() ,a1.end());
      sort(a2.begin() , a2.end());
      int range= r-l+1;
      int s1=0,s2=0; 
      for(int i=0 ;i < range ;i ++ ) {
            s1 += a1[i];
            s2+= a2[i];
      }
      
      cout << min(s1,s2) << endl;
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