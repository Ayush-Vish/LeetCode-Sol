#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     int n,m ;
     cin >> n >>m ;
     string s;
     cin >> s;
     int arr[7]={0};
     for(auto x : s)
     {
         arr[x -'A']++;
     }
     int ans =0 ;

     for(int i=0 ;i < 8; i++  ) {
       if(arr[i]<m)  {
            ans +=( m - arr[i]) ;

      }
     }
      cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}