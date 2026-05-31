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
bool seive(int n)
{
      memset(prime, 1, n + 1);
      for (int i = 2; i * i < n; i++)
            if (prime[i] == 1)
                  for (int j = i * i; j <= n; j += i)
                        prime[j] = 0;
}
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
/**
 * Author: god_ayushv
 */
void solve()
{
      // Write your greatness here
      int n;
      cin >> n;
      int pos = 0, neg = 0;
      int sum = 0;

      int ans = 0;
      int prod = 1;

      for (int i = 0; i < n; i++)
      {
            int ele;
            cin >> ele;
            sum = sum + ele;
            prod *= ele;
      }
      int i = 0;

      while (1)
      {
            if (sum >= 0 && prod == 1)
            {
                  cout << i << endl;
                  return;
            }

            sum += 2;
            prod *= -1;
            i++;
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