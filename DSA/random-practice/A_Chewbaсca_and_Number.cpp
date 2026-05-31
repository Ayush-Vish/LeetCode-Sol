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
/**
 * 
 * int a = 0 ;
 * for i in range(3):
 *    int a=0;
 *    const int n = INT_MAX;
 *    So in this fn we have a array and we need find dp[i] where i is the index in the 
 *    array such that It dp[i] states that max no of fruits we can store in the bucket of 
 *    size k.  
 */

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
      string s;
      cin >> s;

      for (auto &it : s )
      {
            if (it >= '5')
            {
                  it = '9' - it  + '0';
            }
      }
      if (s[0] == '0')
      {
            s[0] = '9';
      }
      cout << s << endl;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      solve();

      return 0;
}