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
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
    const int a=0 ;
    
     // Write your greatness here
     int n ;
     cin  >>n ;
     vector<int>ans ;
     int power =1 ;

     int cnt =0 ;
     while(n)  {
      int last = n%10 ;
      if(last) { 
            ans.push_back(last*power) ;
            cnt ++ ;
      }
      power*=10 ;
      n/=10;


     }

     cout << cnt << endl;
     for(auto it :ans ) {
      cout << it << " " ;
     }
     cout << endl;
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