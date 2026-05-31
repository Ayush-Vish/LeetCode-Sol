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
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } 
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } 
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
bool static comp (pll  p1 , pll p2 ) {
    if(p1.first == p2.first) {
        return p1.second  < p2.second;

    }else {
        return p1.first < p2.first;

    }
}
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    takeInput(a, n);
    takeInput(b, n);
    vector<pll> v;
    for(int i=0 ;i < n ;i ++ ) {
        v.push_back(make_pair(min(p,b[i]) , a[i])) ;
    }
    if(n ==1 ) {
        cout << p  << endl;
        return ;
        
    }
    sort(begin(v),end(v) , comp);

    int ans =  p;
    int rem=n-1;
    for(int i=0 ;i < n -1   ;i ++ ) {
        ans += min(v[i].second ,rem )* v[i].first;
        rem -= min(v[i].second , rem );

    }
    cout << ans <<endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}