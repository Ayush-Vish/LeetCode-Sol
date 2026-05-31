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

void dfs(int i , int j , map<int,int>& mpp , vector<vector<int>>& a, vector<vector<int>>& vis) {
      if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || vis[i][j]) {
          return;
      }
  
      vis[i][j] = true;
  
     
      for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni >= 0 && nj >= 0 && ni < a.size() && nj < a[0].size() && a[i][j] == a[ni][nj]) {
              mpp[a[i][j]]=2  ;
            }
            dfs(ni, nj, mpp, a, vis);
      }
      


  }
  
  void solve() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m)), vis(n, vector<int>(m, false));
  
      map<int, int> mpp;
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
              cin >> a[i][j];
              mpp[a[i][j]] =1 ;

          }
      }
  
      dfs(0, 0, mpp, a, vis);
      int maxi = INT_MIN;
      int ans = 0;
      if(mpp.size() ==1 ) {
            cout << 0 << endl;
      }else {

            for (auto it : mpp) {
                  maxi = max(maxi , it.second);
                  ans += (it.second);
            }
      
      
         
      
            cout << ans- maxi  << endl;
      }
  }
  
  int32_t main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
  
      int t = 1;
      cin >> t;
      while (t--) {
          solve();
      }
      return 0;
  }
  