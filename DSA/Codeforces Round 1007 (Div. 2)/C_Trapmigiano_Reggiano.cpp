#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }


void dfs(int src ,int curr ,  vector<pair<int,int>> &dist , vector<vector<int>> &adj) {
      dist[src ] = {curr , src } ;
      for(auto it : adj[src ] ) {
            if(dist[it].first ==  -1 )  {
                  dfs(it , curr +1 , dist , adj  ) ;
            }
      }
}

void solve(){

      int n ,st,en;
      cin >> n >> st >> en ;
      vector<vector<int>>adj(n);
      if(n ==1 ) {
            cout << 1 << endl;
            return ;
            
      }
      st -- ;
      en -- ;


      for(int i=0 ; i < n-1 ;i ++ ) {
            int p,q ;
            cin >> p >>q ;

            adj[p-1].push_back(q -1 );
            adj[q-1].push_back(p-1 );


      }
      vector<pair<int,int> > dist(n,{-1 ,-1 });
      // dist , node 

      dfs(en,0,  dist , adj ) ;
      // for(auto it : dist) {
      //       cout << it.first << " => " << it.second << endl;

      // }
       sort(dist.begin() , dist.end() , [&](pair<int,int>p1 , pair<int,int> p2 )  {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
      });
      for(auto it : dist) {
            cout << it.second +1  << " ";
      }
      cout <<endl;

      


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1 ;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}