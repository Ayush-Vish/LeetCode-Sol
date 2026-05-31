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
int nod(int n)
{
      int cnt = 0;
      while (n)
      {
            cnt++;
            n /= 3;
      }
      return cnt;
}
const int N = 2e5 + 20;

int cnt[N];
int pre[N];

void solve(){
      int  l, r;
      cin  >> l >> r;
      r ++ ;
      int sum = pre[r] - pre[l];
      int mn = cnt[l];
      cout << sum + mn <<endl;
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      for(int i=0 ; i< N-1 ; i ++ ) {
            cnt[i] = nod(i);
            pre[i +1 ] = pre[i] + cnt[i]; 
      }
      int t;
      cin >> t;
      while (t--)
      {
            solve();
      }
      return 0;
}