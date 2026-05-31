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
int prime[1];
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve(){
    int n ;
    cin >> n; 
    vector<int> v(n);
      for(int i=0; i < n ;i ++ ) {
            cin >> v[i];
            if(i>0) v[i] += v[i-1];
      }
    string s ;
    cin >> s ;
    vector<int> l,r ;
      for(int i=0 ;i < n ;i ++ ) {
            if(s[i] == 'L'     ) {
                  l.push_back(i);
            }
      }
      for( int i= n-1 ; i >=0 ; i -- ) {
            if(s[i] == 'R') {
                  r.push_back(i);
            }
      }
      int pl = 0 ;
      int pr =0 ;
      int ans = 0 ;
      while(pl < l.size() && pr < r.size()) {
            if(l[pl]>= r[pr] ) {
                  break;
            } 
            ans += v[r[pr]];
            if(l[pl] >0) {
                  ans -= v[l[pl] -1 ] ;
            }
            pl ++ ;
            
            pr ++ ;
      }
      cout << ans << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}