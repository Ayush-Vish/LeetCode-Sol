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

map<string, int > mpp ;
void f(int i , string &s) {
      if(i == s.size() -1 ) {
            mpp[s] =1 ;
            return ;

      }
      for (int idx = i ; idx < s.size() ; idx ++ ) {
            swap(s[i] ,s[idx]) ;
            f(i +1 , s ) ;
            swap(s[i],s[idx]);
      }

}
void solve(){
    string s ;
    cin >> s;
      const int n = s.size() ;
      mpp.clear() ;
      f( 0  , s  )  ;
      
      cout  << mpp.size() << endl;
      for(auto it : mpp ) {
            cout << it.first << endl ;

      }     

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//     int t;
        solve();
    return 0;
}