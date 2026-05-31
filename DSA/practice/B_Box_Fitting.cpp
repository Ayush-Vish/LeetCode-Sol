#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n , w ;
      cin >> n >> w;
      vector<int> a(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }

      int cnt =0;
      int rem =0 ;
      int curr =0 ;

      sort(a.begin(),a.end(), greater<int>());

      for(int i = 0 ; i < n ;i ++) {
            if(rem>= a[i]) {
                  rem -=a[i];
            }else {
                  cnt ++ ;
                  rem += (w - a[i]); 
            }
      }
      cout << cnt << endl;

    
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
