#include <bits/stdc++.h>
using namespace std;
#define int long long 

int check(int mid , vector<tuple<int,int,int>> arr )  {
      
      for(int i=0 ; i < arr.size();i ++ ){
            auto [a,b,c] = arr[i];
            if(a >= mid ) {
                  return false;

            }else {
                  mid += b ;
            }
      }
      return true;
}

void solve(){
      int n ;
      cin >> n ;
      vector<tuple<int,int,int>> mv ;
      
      for(int i= 0 ; i < n ;i ++) {
            int k ;

            cin >> k ;
            int maxi =0 ;
            int index = 0 ;

            for(int j=0 ; j < k ;j ++) {
                  int a;
                  cin >>a ;

                  maxi = max(maxi, a - j );
            } 
            mv.push_back({maxi  +1 , k , index});
      }
      // for(auto [a,b,c] : mv )
      //       cout << a << " " << b << " " << c << endl;

      sort(mv.begin(),mv.end()) ;

      int s =0 ;
      int e = 1e9 + 7  ;
      int ans =0 ;

      while(s <= e ){ 
            int mid = (s + (e-s)/2);
            if(check(mid , mv )) {
                  e = mid -1;
                  ans = mid ;

                  
            }else {
                  s = mid +1 ;

            }
      }

      cout << ans -1 << endl;


    
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
