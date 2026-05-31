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

int f(int i , int prev , vector<int>&v , int k ,vector<vector<int>> &dp ) {
    if( i == v.size() ) {
        return 1 ;
    } 

    int ans =0 ;
    if(dp[i][prev] != -1 ) return dp[i][prev] %mod ;
    if(v[i] == 0 ) {
        if(prev -1 >=1 ) {
            ans += f(i +1 , prev -1 ,v ,k , dp ) %mod  ;

        }
        ans += f( i +1 , prev , v ,k,dp) %mod ;
        if(prev +1 <=k ) {
            ans += f(i+1 , prev  +1 ,v ,k,dp) % mod  ;

        }

    }else {
        if(abs (v[i] - prev) <=1  ) {
            ans += f( i+1 , v[i] , v ,k , dp ) %mod  ;

        }else {
            return 0 ;
        }
    }
    return  dp[i][prev] =   ans % mod  ;
}

void solve(){
    int n, k ;
    cin >> n >> k ;
    vector<int>v(n) ;
    for(int i =0 ;i < n; i ++ ) {
        cin >> v[i];
    }
    vector<vector<int>>dp(n+1 , vector<int>(k +1 , -1 ) ) ;
    int ans =0;
    if(v[0] == 0 ) {
        for(int i =1 ;i <=k ; i ++ ) {
            ans += f(1 , i , v ,  k , dp  ) ;
        }
    }else {
        ans+=f ( 1 , v[0],v , k ,dp  ) % mod;

    }
    cout << ans % mod   << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 

        solve();
    
    return 0;
}