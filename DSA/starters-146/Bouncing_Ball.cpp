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
int prime[1];
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
    // Write your greatness here 
    int n;
    cin >>n ;
    vector<int> v(n);
      vector<int> pre(n)  ,suff(n) ;

      for(int i=0 ;i < n ; i ++ ) {
            cin >> v[i];
                  
      }
      pre[0]  =v[0];
      for(int i=1 ;i < n ;i ++ ) {
            pre[i]  =  pre[i-1] + v[i];
      }
      suff[n-1] = v[n-1];

      for(int i=n-2; i >=0 ;i -- ) {
            suff[i]  = v[i] + suff[i +1];
      }
      int ans =0;
      // printArr(pre);
      // printArr(suff);
      if(pre[n-1] ==0 ) {
            cout << n*2 << endl;
            return;
      }
      if(pre[n-1] == 1)  {
            cout << n-1 << endl;
            return;
      }
      for(int i=0 ;i < n ;i ++ ) {
            if(v[i] == 0 && abs(pre[i] - suff[i] ) <=1  ) {
                  ans += (abs(pre[i] -suff[i])) ? 1:2;
                 
            }
      }

      cout << ans << endl;





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
