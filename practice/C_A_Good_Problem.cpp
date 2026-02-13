#include <bits/stdc++.h>
using namespace std;
#define int long long int
int f(int n) {
    if (n == 0) return 0;
    int pos = 0;
    while (n > 0) {
        pos++;
        n/=2;
    }
    return pos;
}
int f2(int n) {
    int pos = f(n);
      // if (pos == 0 || pos >= 63) return 0;
    return 1 << pos;
}
void solve(){
      int n,l,r,k;
      cin >> n >> l >> r >> k ;
      if(n % 2 ==0 ) {
            if( r -  l < 1 ) {
                  cout << -1 << endl;
                  return;
            }else{
                  int next =1 ;
                  while(next <= l ) {
                        next = next*2 ;
                  }
                  if(next > r ) {
                        cout << -1 << endl;
                        return;
                  }else {
                       if(n ==  2 ) {
                         cout << -1 << endl;
                         return;
                       }
                        if(k <=n-2 ) {
                              cout << l << endl;
                        }else{
                               cout << next <<endl;
                        }
                  }

            
            }
      }else {
            cout << l << endl;
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
