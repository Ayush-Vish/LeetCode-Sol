#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
    int n ;
    cin >> n ;
    vector<int> a(n);

    for(int i=0 ; i < n ; i ++) {
        cin >> a[i];
    }

    map<int,int> mpp;

    for(int b=0 ;b < n ;b ++) {
        int num = a[b];
        for(int i=2 ;i*i<= a[b] ; i ++ ) {
            while(num % i == 0 ) {
                mpp[i] ++;
                num /= i ;
            }
        }
        if(num > 1 ) mpp[num] ++;
    }

    for(auto it : mpp) {
        if(it.second % n != 0 ) {
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;
    

     
    
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
