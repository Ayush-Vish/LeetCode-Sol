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
void solve(){
    int x , y ;
    cin >> x >> y ;
    int ans =0 ;
    if ( y>x ) {
        if(y%2!= 0 ) {
            ans = (y*y) -x +1 ;

        }else {
            ans = ((y-1  ) * (y-1 )) + x; 

        }
        cout << ans << endl;
    }else {
        if(x%2 !=0 ) {
            ans= ((x-1 ) *(x-1 ) + y );

        }else {
            ans = (x *x ) - y +1 ;
        }
            cout << ans << endl;
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}