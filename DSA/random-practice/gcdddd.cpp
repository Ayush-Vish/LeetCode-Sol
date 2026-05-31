#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     ll n;
     cin >> n;
      vector<ll> arr(n);
      takeInput(arr,n);
      vector<int> gcdArray(n-1);
      for(int i=0 ;i <n -1 ; i ++ ) {
            gcdArray[i] = __gcd(arr[i] , arr[i+1]) ;
      }
      ll found = 0 ;
      for(int i=0 ;i < n-2 ; i ++ ) {
            if(gcdArray[i] > gcdArray[i+1]     ) {
                  found ++ ;
            }
      }
      if(found ==1 ) {
            cout << "YES"<< endl;

      }else {
            cout<< "NO" << endl;
      }

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