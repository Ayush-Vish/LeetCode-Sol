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



void solve(){
      int n ,k ;
      cin >> n >> k ;
      vector<int>a(n);
      for(int i=0 ;i < n ;i ++ ){
            cin >>a[i];
      }
      if (n ==k ) { 
            vector<int> temp ;
            for(int i=1 ;i < n ;i +=2 ) {
                  temp.push_back(a[i]);
            }            
            temp.push_back(0);
            for(int i=0 ;i  < temp.size();  i ++ ) {
                  if(temp[i] != i+1 )  {
                        cout << i+1 << endl;
                        return;
                  }
            }
      }  
      int cnt = n -  k +1 ;
      for(int i=1 ; i  <= cnt ; i ++ ) {
            if(a[i]  != 1 ) {
                  cout << 1 << endl;

                  return ;
            }
      }
      cout <<2 <<endl;
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