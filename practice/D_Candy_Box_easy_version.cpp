#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      vector<int>a(n);
      map<int,int, greater<int>> mpp;
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
            mpp[a[i]] ++;
      }
      set<int> st;
      vector<int> v;
      for(auto it: mpp) v.push_back(it.second);
      sort(v.begin(),v.end(),greater<int>());
      int ans =v[0] ;
      int prev = v[0];
      for(int i=1 ;i < v.size() ;i ++) {
            prev = min(prev -1 ,v[i]) ;
            if(prev <0 ) break; 
            ans += prev;
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
