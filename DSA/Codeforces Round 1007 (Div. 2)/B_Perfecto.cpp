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

set<int>  sq;

void fill () {
      int n = 5*1e5;
      for(int i=1 ;i <= n ;i ++ ) {
            sq.insert(i*i);
      }
}


void solve(){
      int n;
      cin >> n ;
      int sum = n*(n +1 ) /2 ;
      int sqt = sqrt(sum);
      if (sq.find(sum) != sq.end() || n == 1 ) {
          cout <<  -1  << endl;
      } else {
           vector<int> ans ;
           for(int i=1 ; i <= n ; i ++ ) {
            if(sq.find(i*(i+1)/2) != sq.end()) {
                  ans.push_back(i +1) ;
                  ans.push_back(i ) ; 
                  i ++ ;

            }else {
                  ans.push_back(i);
            }
           }
           for(int i=0 ;i <ans.size() ; i ++ ) {
            cout << ans[i] << " " ;
           }
           cout << endl;
      }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1 ;
    cin >> t;
    fill();
    while (t--){
        solve();
    }
    return 0;
}