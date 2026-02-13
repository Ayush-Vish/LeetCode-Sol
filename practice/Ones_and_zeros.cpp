#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
      int n ;
      cin >> n ;
      queue<pair<int,int>> q;
      q.push({1, 1});

      while(!q.empty()) {
            auto [curr, num] = q.front();
            q.pop();

            if(num % n == 0 ) {
                  cout << num << endl;
                  return;
            }
            
            q.push({1,num*10 + 1 });
            q.push({0,num*10 + 0 });
      }         
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
