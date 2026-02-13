#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      vector<int> u(n +1),s(n +1);

      for(int i=1 ;i <= n;i ++)  cin >> u[i];
      for(int i=1 ;i <=n;i ++)  cin >> s[i];
      vector<vector<int>> v(n+1);

      for(int i=1 ;i <=n ; i ++) {
            v[u[i]].push_back(s[i]);
      }

      for(int i=1 ;i <=n ; i ++) {
            sort(v[i].begin(),v[i].end(), greater<int>());
            int temp =0;

            for(auto & it : v[i]) {
                  temp += it;
                  it = temp;

            }

      }
      vector<int>ans (n+1);
      for(int uni = 1; uni <= n ; uni ++) {
            int len =v[uni].size();

            for(int k=1; k<= len ;k++){
                  ans[k] +=v[uni][ len -(len % k ) -1 ];
            }
      }
      for(int i=1; i<=n ;i ++) cout << ans[i] << " ";

      cout <<endl;
      // for(auto it : v){
      //       for(auto i : it) {
      //             cout << i << " ";

      //       }
      //       cout << endl;
      // }




      
    
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
