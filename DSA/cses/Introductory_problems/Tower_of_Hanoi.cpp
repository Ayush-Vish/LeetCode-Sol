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
vector<vector<int>> ans ;
void f(int n , int src  , int des , int mid    ) {

      if(n == 1 ) {
            ans.push_back({src ,des} );
            return ;

      } 

      f(n-1 , src , mid  , des );
      ans.push_back({src , des});
      f(n-1  , mid  , des , src );


}
void solve(){
      int n ;
      cin >> n ;
      
      f(n , 1, 3 ,2 );
      cout << ans.size() << endl;
      for(int i =0 ;i <  ans.size() ;i ++ ) {
            cout << ans[i][0] << " "<<  ans [i][1] << endl;
      }


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        solve();
    
    return 0;
}