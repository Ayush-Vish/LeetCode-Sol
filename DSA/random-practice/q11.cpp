#include<bits/stdc++.h> 
using namespace std;
void solve() {
   int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ;i < n ;i ++ ) {
        int ele ;
        cin >> ele;
        arr[i] = ele;
    } 
    int mid = n/2;
    int sum1 =0 ;
    int sum2 = 0 ;
    for( int i =0 ;i <mid; i++ ) {
        sum1 += arr[i];
    }
    for(int i= mid  ; i< n; i++) {
        sum2 += arr[i];
    }
    if (n ==1 ) {
        cout <<"YES"<<endl;
        return;
    }
    else if(sum1 > sum2) {
         cout << "YES" <<endl;
    }
    else { 
        cout << "NO" <<endl; 
    }
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}