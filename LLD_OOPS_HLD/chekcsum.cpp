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



string e(string s , int shift  ) {
      string res = "";

      for (char c : s ) {
            if(isalpha(c)) {
                  int base = isupper(c) ? 'A' : 'a';
                  res += char((c - base + shift  )%26 + base );

            }else {
                  res +=c ;

            }
      }

      return res;
}
string d(string s, int shift  ) {
      return e(s , 26 - (shift % 26));
}
void solve(){
    string s = "ayushvis  hwakarma";
    string encrypted = e(s ,4 );
      cout << encrypted << endl;
    string decrypted = d(encrypted,4 );
      cout << decrypted << endl;

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
