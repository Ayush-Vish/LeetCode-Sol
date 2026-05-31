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


// int f(int i , int prev ,vector<int> &arr ) {
      
      
//       if(i == arr.size()) return 0;
//       if(dp[i][prev +1  ] != -1  ) return dp[i][prev+1];
//       int take =0;

//       if(prev ==  -1 ||  arr[i] > arr[prev]) {
//             take = 1 + f(i+1 , i , arr);
//       }
//       int nt = f(i+1 ,prev,arr ) ;

//       return dp[i][prev +1  ] =  max(take , nt);




// }

void solve(){

      int n ;
      cin >> n ;
      vector<int>v;
      for(int i=0 ;i < n ;i ++ ) {
            int val ;
            cin >> val ;
            int idx = lower_bound(v.begin(),v.end(), val )  -v.begin();
            if(idx == v.size()) {
                  v.push_back(val);
            }else {
                  v[idx] = val;
            } 
            cout << "for i => " << i << endl;
            for(auto it : v ) {
                  cout << it << " " ;
            }
            cout << endl;
      }      
      cout << v.size() << endl;


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        solve();
    
    return 0;
}