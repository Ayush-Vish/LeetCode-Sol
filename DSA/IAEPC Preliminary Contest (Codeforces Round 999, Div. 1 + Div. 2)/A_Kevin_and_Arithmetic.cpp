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
      cin >> n;

      vector<int> a(n);
      takeInput(a, n);

      sort(a.begin(), a.end()); 

      vector<int> evens, odds;
      for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
            evens.push_back(a[i]);
      } else {
            odds.push_back(a[i]);
      }
      }

      vector<int> arr(n);
      int evenIndex = 0, oddIndex = 0, index = 0;

      while (evenIndex < evens.size() && oddIndex < odds.size()) {
      if (index % 2 == 0) {
            arr[index++] = evens[evenIndex++];
      } else {
            arr[index++] = odds[oddIndex++];
      }
      }

      while (evenIndex < evens.size()) {
            arr[index++] = evens[evenIndex++];
      }

      while (oddIndex < odds.size()) {
            arr[index++] = odds[oddIndex++];
      }

      // printArr(arr);

      int s=0 ;
      int ans =0;

      for(int i=0 ;i<n;i ++ ) {
            s += arr[i];
            if(s%2 == 0) {
                  s =1 ;
                  
                  ans ++ ;

            }else {
         

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