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
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }

/**
 * Segment Tree is a binary Tree Which has the interval infor and the operation we are performing.
 * ex : sum b/w two integers.
 * a node= {interval , answer of the query}
 *  Segment tree is a Full  Binary tree
 * Leaf = n
 * Interval node = n-1
 * total  = 2*n -1
 *
 */

void solve(){
      int a[] = {3,8,7,6,3,-1,-29,23};
      
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
//     cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
