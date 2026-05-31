#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n ,s;
      cin >> n >>s ;
      vector<int>a(n);
      int sum =0 ;
      int one =0,two=0,zero =0 ;

      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 0) zero ++;
            if (a[i] == 1) one ++;
            if(a[i] == 2 ) two ++;

      }
      int temp = s - sum ;
      if(temp < 0 || temp ==1 ) {
            for(int i=0 ;i < zero ; i ++) {
                  cout << 0 << " ";
            }
            while(one >0 || two > 0 ) {
                  if(two >0 ) cout << 2 << " " , two --;
                  if(one > 0 ) cout << 1 << " ", one -- ;
            }
            cout << endl;
      }else {
            cout << -1 << endl;
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
