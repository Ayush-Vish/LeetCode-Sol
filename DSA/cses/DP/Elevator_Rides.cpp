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
vector<vector<int>> dp ;
int f (int i , int x , int og  ,  vector<int>&a)  {
      if(i == a.size() -1 ) {
            if(x- a[i] >0 ) {
                  return 0 ;
            }
            return 1;
      }
      if(dp[i][x] != -1 ) return dp[i][x];
      int one = INT_MAX;
      if(x - a[i] >0) {
            one = f(i +1 , x- a[i] , og ,a ) ;
      }
      int two = 1 + f(i+1 , og , og ,a );
      return dp[i][x] =   min(one , two ); 
}
void solve(){
      int n, x ;
      cin >> n >> x ;
      vector<int>a(n);
      for(int i=0 ;i < n ;i ++ ) {
            cin >> a[i];
      }
      dp.resize(n,vector<int>(x +1 , -1  )) ;
      cout << 1 + f(0,x , x ,a ) ;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
      solve();
    return 0;
}