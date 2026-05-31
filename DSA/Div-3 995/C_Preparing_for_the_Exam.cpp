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
    int n , m ,k ;
    cin >>  n >> m >> k ;
    vector<int>a(m );
    for(int i=0 ; i < m ;i ++ )
    {
      cin >> a[i];
    }
    unordered_map<int,int> qmap;
    for(int i= 0  ;i < k ; i ++ ) 
    {
      int ele ;
      cin >> ele;

      qmap[ele] =1 ;

    }
    if(n - qmap.size() > 1 ) {
      // cout << " ="<< n - qmap.size() << endl;
      cout << string(m , '0' ) << endl;
      return ;

    }else if(m == qmap.size()) {
      cout << string(m,'1' )<< endl;
      return;
    }
    else {
      string s ="";
      for(int i=0 ;i < m ;i ++ ) {
            if(!qmap.count(a[i]) ){
                  s+='1';
            }else {
                  s  +='0';
            }
      }
      cout << s << endl;
    }
    
    
    

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