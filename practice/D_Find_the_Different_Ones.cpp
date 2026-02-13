#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      
      int n;
      cin >> n ;
      vector<int> a(n);
      vector<pair<int,int>> pre(n),suff(n);
      for(int i=0 ;i < n ;i ++) {
            cin >> a[i];
      }
      pre[0] = { 1,1};
      suff[n-1] = {1, n};
      map<int,int> mpp;
      mpp[a[0]] =1;

      for(int i=1 ; i < n ; i ++ ){
            int temp = mpp.size();
            mpp[a[i]] ++ ;
            if(temp == mpp.size()) {
                  pre[i] = {mpp.size(), pre[i-1].second};
            }else {
                  pre[i] = {mpp.size(), i+1};
            }
      }

      for(int i=n-2 ; i >=0 ; i --) {
            int temp = mpp.size();
            mpp[a[i]] ++;
            if(mpp.size() == temp) {
                  suff[i] = {mpp.size(), suff[i+1].second};
            }else {
                  suff[i] = {mpp.size(), i+1};
            }
      }
      int q ;
      cin >> q ;
      while(q--) {
            int a , b; 
            cin >> a >>b ;
            a -- ;
            b -- ;
            if(pre[a].first == pre[b].first && suff[a].first == suff[b].first) {
                  cout << -1 <<  " "  << -1 << endl;
            }else if(pre[a].first != pre[b].first) {
                  cout << pre[a].second << " " <<  pre[b].second  << endl; 
            }else {
                  cout << suff[a].second << " " <<  suff[b].second  << endl; 
            }
      }
      cout << endl;

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
