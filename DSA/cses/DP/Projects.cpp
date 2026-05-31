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
    cin >> n ;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0 ;i < n ; i ++ ) {
        int l,r,p;
        cin >> l >> r >> p ;

        v.push_back({r,{l,p}});
    }
    sort(v.begin(),v.end());
    vector<int> dp(n+1 ,0);
    dp[0]= 0 ;

    for(int i=1 ; i <= n ; i ++ ) {
        int start = v[i-1].second.first;
        int reward = v[i-1].second.second;
        int prev = lower_bound(v.begin(),v.end() , make_pair(start , make_pair(0LL,0LL))) - v.begin();
        cout << "for i => " << i << " prev => " <<  prev << endl ; 
        dp[i] =max(dp[i-1]  ,reward + dp[prev]);

    }
    cout << dp[n] << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        solve();
    return 0;
}