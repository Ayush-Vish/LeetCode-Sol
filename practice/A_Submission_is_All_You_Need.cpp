#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      int cnt =0;
      int sum =0 ;
      for(int i=0 ;i < n ;i ++) {
            int a ;
            cin >>a; 
            if(a != 0 ) {
                  sum += a ;

            }
            else {
                  cnt ++;
            }
      }      

      cout << sum + cnt << endl;
    
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
