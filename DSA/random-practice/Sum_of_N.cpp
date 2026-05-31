#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e18;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
int largestDivisor(int x ) {
      if(x%2 ==0 ) { 
            return x/2;

      }
      int i =3;
      while(i*i<=(x)) {
            if(x%i ==0 ) {
                  return x/i;
            }
            i = i+2;      
      }

      return 1;
}
int upperInverse (int ld ) {
      if(ld%2 ==0 ) {
            return ld*2;

      }int i =3;
      while(i*i<=(ld)) {
            if(ld%i ==0 ) {
                  return ld*i;
            }
            i = i+2;      
      }

      return 1;


}
void solve()
{
     int k ;
     cin >> k ;
     int range  = k*sqrt(k);
      
      int ans =0 ;

     for(int  i=k  ;i<= range +20 ;i=i+k  ) {
            if(largestDivisor(i) ==k )  {
                  ans = ans%modll +  i%modll ;

            }


     }

     cout <<ans %modll <<"\n";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}