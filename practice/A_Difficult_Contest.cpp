#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      string s;
      cin >>s ;
      if(s.size() <= 2 ) {
            cout << s << endl;
            return;
      }
      string f = "",t ="", str = "", g= "" ;
      int n = s.size();
      for(int i=0 ;i < n ;i ++) {
            if(s[i] == 'F' ) f.push_back(s[i]);
            else if(s[i] == 'T') t.push_back(s[i]);
            else if(s[i] == 'N') g.push_back(s[i]);
            else str.push_back(s[i]);
      }
      int fi = 0;
      int ti =0;
      int j =0 ;
      string ans ="";
      for(int i=0 ;i < n ;i ++) {
            if(fi < f.size()) {
                  ans += f[fi ++ ];
            }
            if(j < str.size()) {
                  ans += str[j ++ ];
            }
            if(ti < t.size()) {
                  ans += t[ti ++];
            }
      }
      for(int i=0 ;i < g.size(); i ++) {
            ans += g[i];
      }

      cout << ans  << endl;
    
    
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
