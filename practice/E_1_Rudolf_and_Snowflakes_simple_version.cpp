#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      if(n % 2 == 0 || n <=6   ) {
            cout << "NO" << endl;
            return;
      }

      n -- ;
      int k = 4; 

      for(int i=6 ; i <= n ; i = i +  k  ) {
            if(i == n ){
                  cout << "YES" << endl;
                  return;
            }
            k += 2 ;
      }
      cout << "NO" <<endl;


    
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
