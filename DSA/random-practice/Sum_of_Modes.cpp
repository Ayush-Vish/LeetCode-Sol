#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
    
    ll n ;
    cin >> n;
    string s;
    cin >> s; 
    unordered_map<ll,ll> mpp;
    ll ans =0 ;
    ll diff  =0 ;
    for(int i=0;i< n;i++ ) {
        if(s[i] == '0' ) {
            diff++;
        } else {
            diff--;
        }

        if(diff == 0) {
            ans++;
        }
        ans  += mpp[diff];
        mpp[diff] ++ ;
    }


    cout <<( (n*(n+1))/2) + ans << endl;
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