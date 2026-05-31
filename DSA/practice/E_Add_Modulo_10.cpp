#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n;
      cin >> n;
      vector<int>a(n);
      bool ok = false;
      int mini = INT_MAX,maxi = INT_MIN;
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
            if (a[i] % 5 == 0) ok = true;
            if(a[i] % 10 ==5 ) {
                  a[i] += 5;
            }
            mini = min(mini,a[i]);
            maxi = max(maxi,a[i]);
      }

      if(ok) {
            if(mini == maxi) {
                  cout << "Yes" << endl;
            }else{
                  cout << "No" << endl;
            }
            return;
      }
      bool f1 =0,f2 =0;
      for(int i=0 ;i < n ;i ++) {
            int x =a[i];
            while (x % 10 != 2) x += x % 10; 
            if(x % 20 ==2 ) {
                  f2 = 1;
            }else{
                  f1= 1;
            }
      }
      if(f1 &f2 ) {
            cout << "No" ;
      }else{
            cout << "Yes" ;
      }
      cout << endl;



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
