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
      int n,m;
      cin >> n >> m ;
      string s;
      cin >> s; 
      // intial black oones
      set<int> st;
      int curr =1;
      for(int i=0 ;i < m ;i ++) {
            int x;
            cin >> x;
            st.insert(x);
      }


      for(auto it : s ) {
            curr ++ ;
            if(it == 'B') {
                  while(st.count(curr) > 0 ) {
                        curr ++;
                  }
            }
            st.insert(curr);
            if(it == 'B') {
                  while(st.count(curr) > 0 ) curr ++;
            }
      }
      cout << st.size( ) << endl;
      for(auto it : st) cout << it << " ";
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
