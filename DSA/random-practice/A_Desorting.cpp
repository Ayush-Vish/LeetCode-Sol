#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
      ll n ;
      cin >> n;
      vector<ll> arr(n);
      takeInput(arr, n);
      ll mini = INT_MAX;
      for(int i=0 ;i<n-1 ;i ++  ) {
            mini = min(mini , arr[i+1] - arr[i]) ;
      }

      if(mini < 0) {
            cout << 0<<endl;
            return ;
      }
      cout <<1 + mini/2<<endl;
   
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