#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<int> siz, parent;
int f(int a ) {
      if(a == parent[a] ){
            return a;
      }
      return parent[a]= f(parent[a]);
}

void solve(){
      int n,m;
      cin >> n >> m ;
      parent.clear();
      siz.clear();
      parent.resize(n+1);
      siz.resize(n+1,1);
      for(int i=0 ;i <=n ;i ++) {
            parent[i] = i ;
      }
      for(int i=1 ;i <= m; i ++) {
            int k;
            cin >> k ;
            if( k> 0 ) {
                  int a ;
                  cin >>a ;
                  for(int j=1 ;j < k ; j ++) {
                        int b; 
                        cin >> b ;
                        int ua = f(a);
                        int ub = f(b);
                        if(ua == ub ) continue;
                        
                        if(siz[ua] >siz[ub]) {
                              parent[ub] =ua;
                              siz[ua] += siz[ub];
                        }else {
                              parent[ua] =ub;
                              siz[ub] += siz[ua];
                        }
                        
                  }
            }

      }
      for(int i=1 ;i<=n ;i ++) {
            cout << siz[f(i)] << " " ;
      }

    
}
bool multi = false;
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
