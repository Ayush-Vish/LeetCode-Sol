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

vector<string >  f(int n ) {
      if (n ==0) {
            return {"0"};
      }
      if(n == 1 ) {
            return {"0", "1"};
      }
      vector<string> temp1 ;
      temp1 = f(n-1 ) ;
      vector<string> temp ;
      for(int i=0 ;i < temp1.size(); i ++ ) {
            temp.push_back("0" + temp1[i]);
      }
      for(int i = temp1.size() -1 ; i>=0 ; i -- ) {
            temp.push_back("1" + temp1[i]);
      }
      
      return temp;
}
void solve(){
      int n;
      cin >> n ;

      vector<string> ans ;
      ans = f(n);
      for(auto it : ans ) {
            cout << it << endl;
      }
      


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
        solve();
    

    return 0;
}