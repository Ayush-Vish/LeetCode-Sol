#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool checkSorted(vector<int> &a)
{
      for (int i = 0; i < a.size() - 1; i++)
      {
            if (a[i] > a[i + 1])
                  return false;
      }
      return true;
}
template <typename T>
void takeInput(vector<T> &a, int n)
{
      for (int i = 0; i < n; i++)
      {
            T ele;
            cin >> ele;
            a[i] = ele;
      }
}
template <typename T>
void printArr(vector<T> &a)
{
      cout << endl;
      for (auto it : a)
      {
            cout << it << " ";
      }
      cout << endl;
}
void solve()
{
      // Write your greatness here
      int n, m;
      cin >> n >> m;
      string x, s;
      cin >> x >> s;
      for(int i=0 ;i < 6 ; i ++ ) {
            if(x.find(s) != string::npos) {
                  cout << i<< endl;
                  return ;
            }
            x  = x+ x ;

      }

      cout << -1 <<endl;
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