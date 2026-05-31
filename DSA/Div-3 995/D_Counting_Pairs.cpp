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
    int n ,x , y ;
    cin >> n >> x >> y ; 
      vector<int>a(n );
      int total =0 ;

      for(int i=0 ;i < n ;i ++ ) {
            cin >> a [i ] ;
            total += a[i];
      }
      sort(a.begin() ,a.end());
      int ans =0 ;
      // for(int i=0 ; i < n ;i ++ ) {
      //       if(total - a[i] <x ){
      //             continue;
      //       }
      //       for(int j = i +1 ;  j <n ;j ++ ) {

      //             if(total -(a[i] + a[j]) >=x &&total -(a[i] + a[j]) <=y) {
      //                   ans ++ ; 
      //             }

                  
      //       }
      // }     


     
    for(int i = 0; i < n - 1; i++) {
       
        
        int mint = total - y - a[i];  
        int maxt = total - x - a[i];  
        
        int left = upper_bound(a.begin() + i + 1, a.end(), mint - 1) - a.begin();
        int right = upper_bound(a.begin() + i + 1, a.end(), maxt) - a.begin();

        if(left < right) {
            ans += right - left;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}