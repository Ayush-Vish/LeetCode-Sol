#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 *    
 *  for i in range:
 *    const int a=0 
 * 
 */

 /**
  * Proof:
  * 
  * 
  */

void solve(){
      int n,k;
      cin >> n >> k ;
      int curr =0;
      vector<pair<int,int>>p(n);
      for(int i=0; i < n ;i  ++) {cin >> p[i].first;};
      
      for(int i=0; i < n ;i  ++) {
            cin >> p[i].second;
            if(p[i].second < p[i].first)  {
                  swap(p[i].first,p[i].second);
            }           
            curr += abs(p[i].first - p[i].second);
      }
      sort(p.begin(),p.end());
      
      int mini = INT_MAX;
      for(int i=1 ;i < n ;i ++){
            if(p[i-1].second > p[i].first) {
                  cout << curr  << endl;
                  return;
            }
            mini = min(mini,p[i].first - p[i-1].second);
      }
      cout << curr + 2*mini << endl;

      



    
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
