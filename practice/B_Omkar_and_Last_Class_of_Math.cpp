#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      if(n % 2 == 0 ) {
            cout << n/2 << " " << n/2 << endl;
            return;

      }
      
      int i=3;

      for(i=3;i *i <=n ;i ++) {
            if(n % i ==0 ) {
                  cout << n/i << " " << n- (n/i) << endl;
                  return;
            }
      }
      cout << 1 << " " << n-1 <<endl;

          
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
