#include<bits/stdc++.h>
using namespace std;

int f(int i , int k ,vector<int>&v) {
      if(k == 0 ) {
            return 1 ;
      }
      if(k<0 || i<0) {
            return 0 ;
      }
      int pick = f(i , k - v[i] , v ) ;
      int np = f(i-1 , k , v ) ;
      return pick  + np ;
}
const int mod = 1e9 + 7;

int main () {
      int n,k ;
      cin >> n >> k; 
      vector<int>v(n);
      for(int i= 0;i < n ;i ++ ) {
            cin >> v[i] ;
      }

      // cout << f(n-1 , x , v ) ;

      vector<int>prev (k+1 , 0 )  ;
      prev[0] =1 ;
     
      vector<int> curr  (k+1,0);
      for(int i=1 ;i<= n ;i ++ ) {
            curr[0] =1 ;

            for(int j = 1 ; j<= k ;j ++ ) {
                  int pick =0 ;

                  curr[j] = prev[j];
                  if(j-v[i-1]>=0) {
                        curr[j] = ((curr[j] %mod ) +  (curr[j-v[i-1]]%mod )%mod );
                  }
            }
            prev = curr;

      }
   

      cout << prev[k]%mod ;


      return 0 ;

}