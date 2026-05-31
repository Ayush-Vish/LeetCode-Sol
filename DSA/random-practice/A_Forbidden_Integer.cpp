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
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
/**
* Author: god_ayushv
*/
void solve()
{
    int n, k ,x ;
    cin >> n >> k >>x ; 
    if(x != 1 ) {
        cout << "YES" <<endl;
        cout << n << endl;
        for (int i=0 ;i < n ;i ++ ) {
            cout << 1 << " ";
        }
        cout <<endl;
    }
    else if (k ==  1 || (k ==2 && n%2 ==1 )) {
        cout << "NO" <<endl;

    }
    else {
        cout << "YES" <<endl;
        cout<<  (n/2) << endl;
        if(n %2 ) {
            cout << 3 << " ";
        }else {
            cout << 2 << " " ;

        }

        for (int i=0 ;i < n/2 -1 ; i ++ ) {
            cout << 2 << " " ;
        }
        cout << endl;
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