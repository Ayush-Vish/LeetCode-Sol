#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int a,b,x,y;
      cin >> a >> b >> x >> y ;
      int ans= 0 ;

      while(a!= b ) {
            if(a < b ) {
                  if(a% 2 == 0 ) {
                        if(y < x) {
                              ans += y ;
                              

                        }else {
                              ans += x ;

                        }
                  }else {
                        ans += x ;

                  }
                  a ++ ;
                  
            }else {
                  if(a % 2 ==1 ) {
                        ans += y ;
                        a -- ;


                  }else {
                        cout << -1 << endl;
                        return;
                  }
            }
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

