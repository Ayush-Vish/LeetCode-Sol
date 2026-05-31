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
    int n;
    cin >> n ;
     int sum = (n*(n+1))/2;
     vector<int>v(n);
      for(int i =1 ; i <= n ; i ++ ){     
            v[i-1]= i ;      
      }


     if(sum %2 ==0 ) {
      cout << "YES" << endl;
     int k = n-1 ;
     int sum1 =0 ;
     vector<int>s1 , s2 ;

     int sum2 =0 ;
      sum = sum /2 ;
     while(k>=0) {
      if(sum1 + v[k] <=sum ) {
            s1.push_back(v[k]);
            sum1 += v[k -- ] ;

      }else {
            s2.push_back(v[k]);
            sum2 +=v[k--] ;
      }
     }

      cout << s1.size()<< endl;
      for(int i = s1.size() -1 ; i >=0 ; i -- ) {
            cout << s1[i] << " " ;
      }
      cout << endl;
      cout << s2.size()<< endl;
      for(int i = s2.size() -1 ; i >=0 ; i -- ) {
            cout << s2[i] << " " ;
      }                 

     }else {      
      cout << "NO" ;
     }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
      solve();
    return 0;
}