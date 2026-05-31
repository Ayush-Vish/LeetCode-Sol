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
void seive(int n)
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
    cout << "Printed Array " << " ";
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}
#define vi vector<int>
#define forn(i, x, n) for (int i = x; i < n; i++)
void solve()
{
    // Write your greatness here
     int q;
    cin>>q;
    int allMin = 1e9;
    vector<vector<int>> arr;

    forn(k,0,q){

        int n;
        cin>>n;

        vi a(n);
        int min1 = 1e9, min2 = 1e9;
        priority_queue<int> pq;
        forn(i,0,n){

            cin>>a[i];
            pq.push(a[i]);
            if(pq.size() > 2) pq.pop();
            allMin = min(allMin, a[i]);
        }
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        arr.pb({ min2, min1 });
    }


    int sum = 0;
    int nowMin = 1e9;
    for(auto &i: arr){

        sum += i[1];
        nowMin = min(nowMin, i[1]);
    }
    sum += allMin;
    sum -= nowMin;
    cout<<sum<<'\n';
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