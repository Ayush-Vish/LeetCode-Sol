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
      int n,m ;
      cin >> n >> m ;
      vector<int>a(n),b(m);
      for(int i=0 ; i < n ;i ++ ) {
            cin >> a[i];
      }
     
      for(int i=0 ; i < m ;i ++  )  {
            cin >> b[i] ;
           
      }
      int idx = min_element(b.begin() , b.end()) - b.begin();
      rotate(b.begin() , b.begin() + idx , b.end());
      // printArr(b);

      for (int i = 0; i <= n - m; i++) {
        bool ok = true;
        for (int j = i; j < i+m; j++) {
            if (b[j-i]> a[j]) {
                ok = false;
                break;
            }else if (b[j-i]==a[j]) {
                  continue;
            }else {
                  ok= true;
                  break;
            }
        }
        if (ok) {
            copy(b.begin(), b.end(), a.begin() + i);   
        }
      }


 
    for (int i = 0; i < n; i++) {
       
       cout << a[i] << " ";
        
    }
    cout << endl;

      
      
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1 ;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}