#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n,m;
      cin >> n >> m ;
      vector<int>a(n);
      map<int,int>mpp;
      for(int i=0 ;i < m ;i ++) {
        int x;
        cin >>x;
        x--;
        a[x] ++;
    }

      auto check = [&](int mid ) -> bool {
        int time =0,work =0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) time += (mid - a[i])/2;
            else work += a[i] - mid;
        }
        return time >= work;
      };


      int s=1;
      int e = 2* m ;
      int ans =1 ;

      while(s <= e ){
        int mid = (s + (e-s)/2);
        if(check(mid)) {
            ans = mid ;
            e = mid - 1;
        }else {
            s = mid +1;
        }
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
    while(t--){
        solve();
    }
    return 0;
}
