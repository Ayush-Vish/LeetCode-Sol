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

// int f( int k , vector<int>&v ) {
    
//     if (k ==0 ) {
//       return 1 ;

//     }

//     if( k < 0  ) {
//       return 0;

//     }
//     if(dp[k] != -1 ) return dp[k];
//     int ans =0;
//     for(int ind =0 ; ind <v.size()  ; ind ++ ) {
//       if(k-v[ind]>=0){
//       ans += f( k-v[ind ],v);

//       }
//     }  
//     return dp[k] =  ans ;

// }

void solve(){
    int n ,k ;
    cin >> n >> k ;
    vector<int>v(n);
    for(int i=0 ; i < n ;i ++ ) {
      cin >> v[i];
    }
    vector<int>dp(k +1 ,-1);
    dp[0] =1 ;
    for(int i=1 ;i  <=k ; i ++) {
      int ans=0 ;

      for(auto it  : v  ) {
        if(i- it>=0) {
          ans = ((ans) %mod +  (dp[i-it])%mod )%mod ;
        }
      }
      dp[i] = ans % mod ;
    }
    cout << dp.back() %mod ;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
      solve();
    return 0;
}