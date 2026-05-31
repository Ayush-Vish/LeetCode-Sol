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
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }

void solve(){
      int n ;
      cin >> n ;
      vector<tuple<int,int,int>> v;
      for(int i= 0;i < n ; i ++ ) {
            int x ,y;
            cin >> x >> y ;
            v.push_back({x , 0, i });
            v.push_back({y , 1, i });
      }
      sort(v.begin() , v.end());
      int size =0;
      vector<int> ans(n);
      stack<int> st;
      for(auto [x,y,i] : v ) {
            if(y == 0 ) {
                  size ++ ;
                  if(st.empty()) {
                        ans[i] = size ;
                  }else {
                        ans [i] = st.top(); st.pop();
                  }
            }else {
                  size -- ;
                  st.push(ans[i]);
            }
      }
      cout << *max_element(ans.begin() ,ans.end()) << endl;
      for(auto it : ans ) {
            cout << it << " " ;
      }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
//     cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
