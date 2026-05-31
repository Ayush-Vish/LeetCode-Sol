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
// vector<vector<int>> dp;
// int f(int i , int j ,  string s , string t ) {
//     if(i < 0) {
//         return j+1 ;
//     }
//     if(j <0) 
//         return i+1 ;

//     if(dp[i][j] != -1 ) return dp[i][j];
//     if(s[i] == t[j]) {
//         return dp[i][j] = f(i-1 , j-1 , s , t ) ;

//     }   
//     return  dp [i][j] = 1   + min ({f(i-1,j,s,t) , f(i,j-1,s,t) ,f(i-1 ,j-1 ,s,t)});   
// }

void solve(){
      string s ,t ;
      cin >> s >> t ;
      int n = s.size();
      int m = t.size();

    //   cout << f(s.size() -1 , t.size() -1  , s ,t ) << endl ;
     vector<int>prev (m+1 , 0 ) ;
    for(int j=0 ; j<=m ;j ++ ) {
        prev[j]=j;
    }
   

    for(int i=1 ; i <=n ;i ++ ) {
        vector<int>curr(m,0);
        curr[0]=0 ;

        for(int j=1 ; j<=m ;j++ ) {
            if(s[i-1] == t[j-1]) {
                curr[j]= prev [j-1];
            }else {
                curr[j] = 1+  min({prev[j],curr[j-1],prev[j-1]});
            }
        }
        prev = curr;
    }

    cout << prev[m];
    


      
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        solve();
    
    return 0;
}