#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans  = 0;
    int  prefixSum = 0, maxElement = -1;
    for (int i = 0; i < n; i++) {
        prefixSum += a[i];
        maxElement = max(maxElement, (long long)a[i]);
        if ( prefixSum - maxElement == maxElement) {
            ans ++;
        }
    }

    cout << ans  << "\n";


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