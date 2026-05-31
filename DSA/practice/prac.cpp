#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  * 
  */


string  q1(string a ) {
      if(a.size()  % 2 == 0 ) {
            for(int i=0  ;i < a.size() ; i ++) {
                  if(a[i] >='a' && a[i] <'z') {

                  }else{
                        a[i] = a[i] -'A' + 'a';
                  }
            }
      }else{
            for(int i=0  ;i < a.size() ; i ++) {
                  if(a[i] != 'z'){
                        a[i] = a[i] +1;
                  }else{
                        a[i] = 'a';
                  }
            }
            cout << endl;
      }
      return a;
      
}
string q2(string a ) {
      int n = a.size();
      int curr = a[0] - '0';
      char prev = a[0];
      for(int i=1 ;i < n ;i ++) {
            while(prev == a[i]) {
                  curr += a[i] - '0';
            }
            curr += 

      }
}
void solve(){
      cout << q1("fsdkjhnfkldsfDSADSADS") << endl;
      cout << q1("fsdkjhnfkldsfDSADSAD") << endl;

      // ------------------------------------------// 
      cout << q2("298347328947932222223535454") << endl;
     
}
bool multi = false;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
