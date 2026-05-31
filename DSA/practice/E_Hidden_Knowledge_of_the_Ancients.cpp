#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  *   n,k,l,r = 5 2 2 3
      arr = 1 2 1 3 2
      now f(2) - f(1)
      f(2):
            map= {
                  1 => 1
                  2 => 2 
            }
            cnt = 1 
            1 2 1 3 2
                    i
                j
  */              

void solve(){
      int n,k,l,r;
      cin >> n >> k >> l >> r; 
      vector<int>a(n);
      for(int i=0 ;i < n ;i ++)  cin >> a[i];

      auto f = [=] (int k) ->int {
      
            map<int,int> mpp  ;
            int ans =0 ;
            for(int i= 0,j =0  ;i < n ;i ++) {
                  mpp[a[i]] ++;
                  while(mpp.size() >k && j <=i  ){
                        mpp[a[j]] --;
                        if(mpp[a[j]] == 0 ) mpp.erase(a[j]);
                        j  ++ ;
                  }
                  ans += max(0LL,(min(i-j+1,r) - l+1));
            }     
            return ans;

     };
     cout << f(k) - f(k-1) << endl;
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
