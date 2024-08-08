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

class comp
{
    public:
    bool operator()(const pll &a, const pll &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
void solve()
{
    // Write your greatness here
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    takeInput(a, n);
    takeInput(b, n);

    priority_queue<pll, vector<pll>, comp> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({a[i], b[i]});
    }
    int ans = p;
    n = n - 1;
    while (n >= 0)
    {
        auto node = pq.top();
        while (node.first--)
        {
            n--;
            ans += node.second;
        }
    }

    cout << ans << endl;
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