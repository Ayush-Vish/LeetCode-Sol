#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     ll n ;
     cin >> n ; 
     vector<ll> a(n);
      takeInput(a,n);
      vector<ll> b(n); 
      takeInput(b,n);
      ll m;
      cin >> m ; 
      vector<int> d(m);
      takeInput(d,m);
      multiset<ll>s;
      for(int i=0 ;i < n ;i ++ ) {
            if(a[i] == b[i]) {
                  continue;
            }
            s.insert(b[i]);
      }
      for(int i=0;i<m ;i ++ ) {
            auto it = s.find(d[i]);
            if(it != s.end()) {
                  s.erase(it);
            }
      }
      if(!s.empty()) {
            cout <<"NO"<<endl;
            return ; 
      }
      ll last  = d.back();

      bool flag = false;
      for(auto it: b ) {
            if(it ==last ) {
                  flag=  true;
            }
       }


       if(flag) {
                  cout << "YES"<<endl;
       }else {
                  cout << "NO"<<endl;
       
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