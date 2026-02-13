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

void solve(){
       int n;
      cin >> n;

      if (n == 0) {
            cout << "YES" << endl;
            return ;
      }

      int size = (int)floor(log2(n)) + 1;


      cout << size << endl;

      string s(size, '0');
      int j = size - 1;

      while (n > 0) {
            int rem = n % 2;
            s[j] = '0' + rem;
            j--;
            n /= 2;
      }

      cerr << s << endl;
      string temp = s;
      // reverse(s.begin(),s.end());
      // bool ok = true;
      // string ans(size,'0');
      // for(int i=0 ;i < size; i ++) {
      //       if(((s[i]-'0' )&(temp[i] - '0') )==1 ) {
      //             ans[i] ='1';
      //       }else{
      //       }
      // }
      // cout << ans << "-> " << temp << endl;
      // if(ans == temp ) {
      //       cout << "YES" << endl;
      // }else{
      //       cout << "NO" <<endl;

      // }
      // if(ok){
      // }else{
      // }




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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
