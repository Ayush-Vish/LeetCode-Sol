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
    string s ;
    cin >> s ;
    unordered_map<char , int > mpp ;
    for(auto it : s ) {
      mpp[it ] ++ ;

    }
    int odd =0, even =0 ;
    char oddChar= ' ' ;
      // cout << "ddsfds" << endl;
    for(auto it : mpp) {
      if(it.second &1 ) {
            odd ++ ;
            oddChar = it.first;

      }else {
            even ++ ;

      }


    }
   
    if( odd != 1 && odd != 0  ) {
      cout << "NO SOLUTION" << endl;
      return ;
    }else {
      string ans ="";
      for(auto it : mpp  ) {
            if (it.second %2 ==0 ) {
                  for(int i=0 ;i < it.second/2 ;i ++ ) {
                        ans += it.first;
                  }
            }
      }
  
      string two = ans ;
      reverse(two.begin(), two.end()) ;
      if(oddChar == ' ' ) {

      ans = ans  + two;
      }else {

            for(int i =0 ;i < mpp[oddChar] ; i ++ ) {
                  ans += oddChar;
            }
            ans += two ;
            

      }

      cout << ans << endl;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        solve();
    
    return 0;
}