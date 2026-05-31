#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     int n,m  ;
     cin >> n >> m ;
     vector<vector<char>> a(n , vector<char>(m));     
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               cin >> a[i][j];
          }
      }



      pll upper;
      pll lower ;
      for(int i=0 ;i<n ;i ++ ) {
            for(int j =0 ; j<m ;j ++ ) {
                  if(a[i][j] == '#' ) {
                        upper = {i,j};
                        break;
                  }
            }
      }
      for(int i=n-1 ;i>=0 ;i -- ) {
            for(int j =m-1 ; j>=0 ;j --  ) {
                  if(a[i][j] == '#' ) {
                        lower = {i,j};
                        break;
                  }
            }
      }

      int x = ceil(float((upper.first + lower.first)/2));
      cout << x  + 1<< " " <<  upper.second +1  << endl;


}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}