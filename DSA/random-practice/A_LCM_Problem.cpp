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
int gcd(int a, int b)
{
      if (b == 0)
            return a;
      return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
      return (a / gcd(a, b)) * b;
}
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
void solve()
{
      // Write your greatness here
      int l, r;
      cin >> l >> r;
      if(2*l > r ) {
            cout << -1 << " " << -1 ;

      }
      else {
            cout << l << " " << 2*l  ;

      }
      cout <<endl;
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