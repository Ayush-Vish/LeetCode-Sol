#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
vector<int> primes;
bool check(int num1 , int num2) {
      string s = to_string(num1), t = to_string(num2);
      int cnt =0;
      for(int i=0 ;i < s.size() ; i ++) if(s[i] != t[i]) cnt ++;
      return cnt ==1 ;
}
vector<int> v;

const int maxi = 100001;
vector<int> adj[maxi];

void build() {
    primes.resize(maxi, 1);
    primes[0] = primes[1] = 0;

    for (int i = 2; i * i < maxi; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxi; j += i)
                primes[j] = 0;
        }
    }

    for (int i = 1000; i < 10000; i++) {
        if (primes[i]) v.push_back(i);
    }
    for(int i=0 ;i  < v.size() ; i ++) {
          for(int j= i+1 ; j  < v.size() ; j ++) {
                if(check(v[i],v[j])) {
                      adj[v[i]].push_back(v[j]);
                      adj[v[j]].push_back(v[i]);
                }
          }
    }
}
void solve(){
      string s,t ;
      cin >> s >>t ;

      queue<pair<int,int>> q;
      q.push({stoi(s),0});
      while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(to_string(top.first) == t ) {
                  cout <<  top.second << endl;
                  return;
            }
            for(auto it : adj[top.first]) {
                  if(it != top.first)
                        q.push({it, top.second  +1 });
            }

      }
      cout << "Impossible" << endl;
    
}
bool multi = true;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    build();
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
