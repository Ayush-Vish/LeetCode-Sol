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

void solve()
{
      int n;
      cin >> n;
      int k = n;
      vector<int>ans ;

      for (int i = 0; i <n / 2; i++)
      {     
            ans.push_back(-1);
            ans.push_back(3);

      }
      if(n % 2 ==1 ) {
            ans.push_back(-1);
      }else{
            ans.back() =2 ;
      }
      for(auto it : ans )
            cout << it << " ";
      cout << endl;
}
bool multi = true;
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      int t = 1;
      if (multi)
            cin >> t;
      while (t--)
      {
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
