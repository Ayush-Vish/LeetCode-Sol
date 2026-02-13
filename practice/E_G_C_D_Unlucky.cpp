#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * Dont think to pass the test cases.
 * Like if we have a a[i ] means we can divede the prevoios all elements with the this no.
 * same goes to the b[i];
 *  waht i am thinking is to jsut 
 * take the gcd of the pre and suff and check if the gcd is same in the Array.
 *                      
 *              IS IT ENOUGH:
 *                  So 
 *  Not so:
 *      
 * 
 *      
 *  
 */

 /**
  * Proof:
  * 
  */

void solve(){
    int n ;
    cin >> n ;
    vector<int> a(n),b(n);
    for(int i=0 ;i < n ;i ++) {
        cin >> a[i];
    }
    bool ok =0;
    
    vector<int> res(n);
    for(int i =0 ;i < n ;i ++) {
        cin >> b[i];
        res[i] = lcm(a[i],b[i]);
    }

    for(int i=1 ;i < n ;i ++) {
        if(a[i-1] % a[i] != 0 ){
            ok = 1;
            break;
        }
        
    }
    for(int i=n-1 ; i>=1 ; i -- ) {
        if(b[i] % b[i-1] !=0 ) {
            ok = 1;
            break;
        }
    }

    int g = res[0];
    for(int i=0 ;i < n ;i ++) {
        g =  gcd(g,res[i]);
        if(g != a[i]) {
            ok = 1;
            break;
        }
    }

    g = res[n-1];
    for(int i=  n-1 ;i >=0 ; i -- ) {
        g = gcd(res[i],g);
        if(g != b[i]) {
            ok  =1 ;
           break; 
        }
        
    }

    if(ok == 1 ){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
   

    
    
}   
//    vector<int> res(n);
//    for(int i=0 ;i <=n/2 ; i ++) {
//     res[i] = a[i];
//    }
//    for(int i=n/2 +1  ; i < n ;i ++) {
//     res[i] = b[i];
//    }
//    for(auto it :  res) {
//     cerr << it << " ";
//    }
//    cerr << endl;
//    int curr =0 ;
//    for(int i=0 ;i < n;i ++) {
//     curr = gcd(curr,res[i]);
//     if(a[i] != curr) {cout << "NO" << endl;return;}
//    }
//    curr =0;
//    for(int i=n-1 ;i>=0;i -- ) {
//     curr = gcd(curr,res[i]);
//     if(b[i] != curr) {cout << "NO" << endl;return;}
//    }
//    cout << "YES" << endl;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */   
