#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n + 1);
    takeInput(a, n);
    takeInput(b, n + 1);

    ll ans = 0;
    ll ans2 = 1e9;

    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
        if (a[i] <= b[n] && b[i] >= b[n])
        {
            ans2 = 1;
        }
        if (a[i] >= b[n] && b[i] <= b[n])
        {
            ans2 = 1;
        }
        ans2 = min(ans2, abs(a[i] - b[n]) + 1);
        ans2 = min(ans2, abs(b[i] - b[n]) + 1);
    }
    cout << ans + ans2 << endl;
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