#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;cin >> n ;
      vector<int>v[n];
      map<int,int> m;

      for(int i=0 ; i < n ;i  ++) {
            int k;cin >> k ;
            for(int j=0 ; j < k ;j ++) {
                  int a;
                  cin >>a ;
                  v[i].push_back(a);
                  m[a] ++;
            }
      }

      bool flag  = false;
      for( int i=0 ; i < n ;i ++) {
            bool f = true;
            for(int j=0; j < v[i].size(); j ++) {
                  if(m[v[i][j]] <2 ) {
                        f =false;
                  }
            }
            flag  |= f; 
      }
      if(flag) {
            cout << "YES" ;
      }else{
            cout << "NO";
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
