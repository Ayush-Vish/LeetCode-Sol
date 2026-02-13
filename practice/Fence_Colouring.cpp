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
      map<int,int> mpp;
      int maxi = 0;
      int ele = 0;
      for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mpp[x]++;
      }
      for(auto it = mpp.rbegin(); it != mpp.rend(); ++it){

            if(it->second >= maxi){
                  maxi = it->second;
                  ele = it->first;
            }
      }
      if(ele == 1){
            cout << n - mpp[ele] << endl;
      }else{
            cout << 1 + (n - mpp[ele]) << endl;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
