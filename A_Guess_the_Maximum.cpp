#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pll pair<ll, ll>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
      ll n ;
       cin >> n;
       vector<ll> arr(n);
       takeInput(arr, n ) ;
       ll maxi = 1e9+1 ;
       for(ll i=1 ;i<n ; i ++ ) {
            ll s = max(arr[i-1] , arr[i]) ;
            maxi = min(maxi , s) ;
       }
       cout << maxi -1 << endl;
        fflush(stdout);
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