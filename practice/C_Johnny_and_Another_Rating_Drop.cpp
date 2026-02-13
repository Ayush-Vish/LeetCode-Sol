#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){

      int n;
      cin >> n;
      int ans = 0;
      int p = 1;
      while( true ) {
            int temp = n/p;
            if(temp == 0 ) break;

            ans += temp;

            p <<=1;

      }
      cout << ans << endl;
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
