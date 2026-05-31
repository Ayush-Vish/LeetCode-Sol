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
template <typename T> void printArr(vector<T> &a) { cout << "\n"; for (auto it : a) { cout << it << " "; } cout << "\n"; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
void solve(){
      int n ;
      cin >> n ;
      vector<int>a(n);
      vector<int> dup;

      map<int,int> mpp;
      for(int i=0 ;i < n ;i ++ ) {
            cin >> a [i];
            mpp[a[i]] ++ ;
            if(mpp[a[i]] ==2  ) {
                  dup.push_back(a[i]);
            } 
      }
      if(dup.size() == 0){
            cout  << -1 << "\n";
            return ;

      }
      if(dup.size() >1 ) {
            cout << dup[0] << " " << dup[0] << " " << dup[1] << " " << dup[1] << "\n";
            return;
      }
      int val = dup[0];
      vector<int>temp;
      int cnt =2;
      sort(a.begin(),a.end());
      for(auto it : a ) {
            if(it == val && cnt > 0 ) {
                  cnt -- ;
                  continue;
            }
            temp.push_back(it);

      }

      bool ok = false;
      for(int i=0 ;i < temp.size()-1 ; i ++  ){
            if(temp[i+1 ]< (temp[i] + 2*val)) {
                  cout << val << " " << val << " " << temp[i] << " " << temp[i+1 ] << "\n";
                  return;                  


            }
      }

      cout << -1 << "\n";
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