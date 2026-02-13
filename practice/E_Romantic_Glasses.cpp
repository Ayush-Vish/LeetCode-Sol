#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int
void solve(){
    int n ;
    cin >> n ;
    vector<int> a(n);
    for(int i=0 ;i < n ;i ++) {
        cin >> a[i];
        if(i % 2 ==0 ){
            a[i] = -a[i];
        } 
    }
    map<int,int> mpp;
    mpp[0] =1;
    int curr =0 ;


    for(int i=0; i <n ;i ++) {
        curr += a[i];
        if(mpp[curr]){
            cout << "YES" << endl;
            return;
        }
        mpp[curr] ++;
    }
    cout << "NO" <<endl;
      
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
