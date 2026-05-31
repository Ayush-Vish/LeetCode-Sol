#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int fastPow(int a, int b) { int res = 1; while (b) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }

vector<int> seive(int n ) {
      vector<int> prime(n+1 ,1 ) ; // (n)
      for(int i=2 ;i*i <=(n);i ++) {
            if(prime[i]) {
                  for(int j=i*i; j<=n ;j+=i){
                        prime[j]=0;
                  }
            }
      }
      // time complexity : Nlog(log(N))
      return prime;
}

void solve(){
      int n ,k;
      cin >> n >> k ;
      // queue<int> q ;
      // for(int i=1 ;i <= n ;i ++ ) {
      //       q.push(i);
      // }
      // while(q.size() >0 ) {
      //       int temp = k%q.size() ;
      //       while(temp -- ) {
      //             int a = q.front();
      //             q.pop();
      //             q.push(a);
      //       }
      //       cout << q.front() << " " ;
      //       q.pop();
      // }
      indexed_set s ;
      for(int i=1 ;i <=n ;i ++ ) {
            s.insert(i);
      }
      int ind = k%n ;

      while(n--) {
            auto u = s.find_by_order(ind);
            cout << *u << " ";
            s.erase(u);
            if(n) ind = (ind%n +k)%n;
      }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1 ;
//     cin >> t;
    while (t--){
        solve();
    }
    return 0;
}