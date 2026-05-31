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
      int n ,m,k;
      cin >> n >> m >> k ;
      vector<int> a(n);
      takeInput(a,n);
      vector<int> b(m);
      takeInput(b,m);
      
      int ans =0 ;
      sort(a.begin() , a.end());
      sort(b.begin(),b.end());
      int i=0;
      int j =0 ;
      int cnt =0 ;
      while(j<m && i<n) {
            
            if((a[i]- k ) <=b[j] && (a[i]+k )>=b[j] ) {
                  cnt ++ ;
                  j ++;
                  i ++ ;
            }else if((a[i]- k) >b[j] && (a[i] + k )> b[j ]) {
                  j ++ ;

            }else if (a[i]- k <b[j] && a[i] + k < b[j ]) {
                  i ++ ;
            }

      }
      cout << cnt << endl;




}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        solve();
    
    return 0;
}