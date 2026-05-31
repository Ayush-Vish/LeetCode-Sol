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
            int n,c;
            cin >> n >> c ;
            vector<int>a(n);
            for(int i=0 ;i < n ;i ++){
                  cin >> a[i];
            }     
            
            sort(a.rbegin(),a.rend());

            int cnt =0;

            for(int i=0;i < n ;i ++) {
                  if(a[i]*(pow(2,cnt)) <=c) cnt ++;
            }
            cout << n - cnt << endl ;

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
      /**
       * Golden rule no. 1:
       *    Solutions are simple.
       * Golden rule no. 2:
       *    Implementation is simple
       * Golden rule no. 3:
       *    Above two are always correct
       */
