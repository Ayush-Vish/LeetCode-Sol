#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  * 
  */

void solve(){
    int n ;
    cin >> n ;
    vector<vector<int>> a(n,vector<int>(n,0));
    int k =1 ;

    a[0][(n-1)/2] = k;

    int cnt = 1;
    int r = 0;
    int c = (n-1)/2;
    
    while(cnt <n*n) {
        k ++ ;
        if(  a[(r-1+n )%n][(c +1)%n]== 0  ) {
            a[(r-1+n)%n][(c +1)%n]= k ;
            r = (r-1+n)%n;
            c= (c +1)%n;
        }else{
            a[(r+1)%n][c]= k;
            r = (r+ 1)%n;
        }
        cnt ++ ;

    }
    for(auto it : a ) {
        for(auto i : it  ) {
            cout << i<< " " ;
        }
        cout << endl;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
