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

struct range {
    int l,r,i;
    bool operator < (const range & other ) const {
        if(l == other.l) {
            return r > other.r;
        }
        return l < other.l;
    }
};

void solve(){
    int n ;
    cin >> n ;
    vector<range> v(n);
    for(int ii=0 ;ii < n ;ii ++ ) {
        cin >> v[ii].l >> v[ii].r;
        v[ii].i= ii ;
    }
    sort(v.begin() ,v.end()) ;
    vector<int> a1(n),a2(n);
    int maxi = 0 , mini = INT_MAX;
    
    for(int i= n-1 ;i  >=0  ;i -- ) {    
        if(v[i].r >=  mini) {
            a1[v[i].i] = 1 ;
        }
        mini = min(mini , v[i].r);
    }

    for(int i =0 ;i < n ;i ++ ) {
        if(v[i].r <= maxi ) {
            a2[v[i].i] = 1;
        }
        maxi = max(maxi, v[i].r);
    }
    for(auto it : a1 ) {
        cout << it << " " ;
    }
    cout << endl;
    for(auto it : a2 ) {
        cout << it << " " ;
    }
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
