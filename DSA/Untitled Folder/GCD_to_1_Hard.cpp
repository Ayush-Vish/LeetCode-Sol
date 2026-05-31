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
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;return true;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; }
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
/**
* Author: god_ayushv
*/
void solve()
{
    // Write your greatness here
    int n , m ;
    cin >> n >> m  ;
      int a[n][m] ;
      
    for(int i =0  ;i < n ;i ++ ) {
      for(int j =0 ; j < m ;j ++ ) {
            a[i][j] =2 ;

      }
    }
    if(n > m ) {
      for(int i=0 ;i < m ;i ++ ) {
            a[i][i] = 3 ;

      }
      for(int i = m ; i < n ;i ++ ) {
            a[i][0] = 3 ;

      }


    }else {
      for(int i=0 ;i < n ;i ++ ) {
            a[i][i] = 3 ;

      }
      for(int i = n ; i < m ;i ++ ) {
            a[i][0] = 3 ;

      }
    }
    for(int i= 0 ;i < n ;i ++ ) {
      for(int j=0 ; j < m ;j ++ ) {
            cout << a[i] [j ] << " " ;

       }
       cout << endl;
    }
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