#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int a , b , k;
      cin >> a >> b >>k ;
      int x = gcd(a,b);
      int y = (a + k -1  )/k;
      int z = (b + k -1 ) /k ;
      if(z > y ) {
            swap(z ,y );

      }     
      if(x >= y ) {cout << 1 << endl;}
      else {cout << 2 << endl;}
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
