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

int f (int i , int n , int sum , vector<vector<int>>&dp ) {
      if(sum < 0  || i >n ) {
            return 0; 
      }   
      if(sum == 0 ) {
            return 1 ;
      }
      if(dp[i][sum]  != -1 ) {
            return dp[i][sum]%mod ;
      }
      int take = f(i+1 , n,sum - i , dp )%mod ;
      int nt = f(i+ 1 , n,sum ,dp )%mod ;
      return dp[i][sum ] =  (take + nt)%mod  ;
}

void solve(){
      int n ;
      cin >> n ;
      int sum = ((n*(n+1))/2)%mod ;
      if(sum%2 ==0 ) {
            sum = sum/2;
            vector<vector<int>> dp(n+1 ,vector<int>(sum +1 , -1 ) );
            cout << f(1 ,n,sum ,dp ) % mod ;

      }else {
            cout << 0 << endl;

      }
}
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      solve();
    return 0;
}