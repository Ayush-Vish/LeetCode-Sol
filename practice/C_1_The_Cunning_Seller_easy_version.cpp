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
// int INF = 1e18;

// vector<vector<int>> dp;

// int f(int i , int k ,  vector<pair<int,int>>&a  ) {
//       if(k == 0 ) {
//             return 0;

//       }
//       if (k < 0 || i >= (int)a.size()) return INF;


//       int take = a[i].second + f(i , k - a[i].first, a);
//       int nt= f(i+1 , k, a );
//       return min(take,nt);

// }

// void solve(){
//       int n ;
//       cin >> n ;
//       int len = 19 ;
//       dp.resize(len,vector<int>)
//       vector<pair<int,int>> a;
//       for (int i = 0; i < len; i++) {
//             int w = 1;
//             for (int j = 0; j < i; j++) w *= 3;   // w = 3^i
//             int cost = w * 3;
//             if (i > 0) cost += i * (w / 3);      // i * 3^(i-1)
//             a.push_back({w, cost});
//       }
//       for(auto it : a )
//             cout << it.first << " " << it.second << endl;
//       cout << " fdb" << endl;
//       // cout << f(0,n , a ) << endl;
// }




int maxi = 19 ;
vector<int> p,cost;

void solve() {
      int n;
      cin >>  n;
      int ans  =0;

      for(int i=0 ; n > 0 &&  i <= 19 ; i  ++ ) {
            int ld = n % 3 ;
            ans += (1LL*ld * cost[i] );
            n/=3 ;
      }
      cout << ans << endl;
}


bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
      p.resize(maxi +1,1  ), cost.resize(maxi +1 );
      for(int i=1; i <=maxi ; i ++) {
            p[i] = p[i-1]*3;
      }
      for(int i=0;i<=maxi ; i ++) {
            int c = p[i] * 3;
            if (i > 0) c +=  i * p[i - 1];
            cost[i] = c;
      }
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
