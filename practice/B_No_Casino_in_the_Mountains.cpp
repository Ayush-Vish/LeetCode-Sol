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
   int n , k ;
   cin >> n >> k ;
   vector<int>a(n);
   for(int  i=0 ;i < n ;i ++ ) {
      cin >> a[i];
   } 
   int ans =0;
   for(int i=0 ;i < n ;i ++) {
      int cnt =0 ;
      while(a[i] == 0 && i < n ) {
            cnt  +=1 ;
            i ++;
      }

      if(cnt/k ==0){continue;}
      int time = cnt/(k +1 );


      
            cnt -=(time);
            
      
      ans += cnt/k;
      if(a[i] ==1 ) continue;
      
   }
      
   cout <<ans << endl;
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
