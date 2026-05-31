#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve()
{
      int n;
      cin >> n;
      string s = "";
      int p = -1;

      int cnt =0;

      for(int i=0 ;i < n ; i ++) {
            char ch;
            cin >> ch ;

            if(ch == '*') {
                  cnt ++;
            }
            s +=ch;
      }

      int mid = -1;
      int curr =-1 ;
      
      for(int i =0; i < n ;i ++) {
            if(s[i] == '*') {
                  curr ++;
                  if(cnt / 2 == curr ) {
                        mid = i;
                  }
            }
      }
      if(mid == -1) {
            cout << 0 << endl;
            return;
      }     
      int ans =0;
      curr = mid - cnt /2 ;


      for(int i=0 ; i < n ;i ++) {
            if(s[i] == '*') {
                  ans += abs(curr - i );
                  curr ++ ;
            }
      }
      cout << ans << endl;
      

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
