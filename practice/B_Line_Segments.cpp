#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;
      cin >> n ;

      int px,py,qx,qy;
      cin >> px >> py >> qx >> qy ;
      vector<int> a(n );
      double sum = 0 ;
      int maxi = 0 ;
      for(int i=0;i <  n; i ++) {
            cin >>a [i];
           sum += a[i];
           maxi =max(maxi,a[i]);
      }

      double q =max((double)(maxi - (sum - maxi)), 0.0 );
      double d= sqrt((px - qx) * (px - qx)  + (py - qy) * (py - qy)  );
            if(q <= d && d <= sum ) {
                  cout << "Yes" ;
            }else{
                  cout << "No" ;
            }
      cout <<endl;
    
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
