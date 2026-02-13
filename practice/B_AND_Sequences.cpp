#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
const int  mod = 1e9+7;
void solve(){
      int n ;
      cin >> n ;
      vector<int>a(n);
      for(int i=0 ;i < n ;i  ++) cin >> a[i];

      int mini = *min_element(a.begin(),a.end());
      int cnt= 0 ;
      // (a & b) <= min(a,b); 
      for(int i=0 ;i < n ;i ++) {
            if ( mini ==a[i] ) cnt ++;
            if((a[i] & mini) != mini ){
                  cout << 0 << endl;
                  return;
            }
      }

      if(cnt <2 ) {
            cout << 0 << endl;
            
      }else {
            int fact =1;
            for(int i=1 ;i <=n-2;i ++) {
                  fact =(( fact % mod )*( i % mod) )% mod ;
            }
            cout << (cnt % mod * (cnt  -1 ) % mod  * fact  % mod ) % mod << endl;

      }


}
bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
