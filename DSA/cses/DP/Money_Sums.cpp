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
set<int> st;
vector<vector<int>> dp;

void f(int i ,int sum ,  vector<int>&v ) {
    

    if(i == v.size()) {
        st.insert(sum);
        return ;
    }
    if(dp[i][sum ] != -1 ) {
        return;
    }
    f(i+1 , sum + v[i] , v ) ;
    f(i+1 , sum , v ) ;
    dp[i][sum ] = 1;
}

void solve(){
    int n ;
    cin >> n ;
    vector<int>a(n);
    for(int i=0 ; i < n ;i ++ ) {
        cin >> a[i];
    }
    st.clear();
    int tot = accumulate(a.begin(),a.end(),0);
    dp.assign(n+1 ,vector<int>(tot +1 , -1 ) );
    f(0 , 0, a ) ;
    st.erase(st.begin());
    cout << st.size() << endl;
    for(auto it: st ) {
        cout << it << " ";
    }
    cout << endl;


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
  
        solve();
    
    return 0;
}