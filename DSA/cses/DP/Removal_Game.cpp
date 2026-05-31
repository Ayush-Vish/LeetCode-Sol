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

vector<vector<int>> dp;


int f(int i , int j , vector<int>&a) {
      if(i > j) return 0;
      if(dp[i][j] != -1 ) {
            return dp[i][j];
      }

      int t1= a[i] + min(f(i+2 , j ,a ) , f(i+1 ,j-1 ,a )) ;
      int t2= a[j] + min(f(i +1 , j-1  ,a ) , f(i ,j -2  ,a )) ;
      return dp[i][j] =  max(t1,t2);
}


void solve(){
      int n ;
      cin >> n ;
      vector<int> a(n);
      takeInput(a,n);
      dp.assign(n,vector<int>(n,-1));
      cout << f (0,n-1 ,a );
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
    return 0;
}