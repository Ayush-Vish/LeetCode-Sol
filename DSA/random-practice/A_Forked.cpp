#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     int a,b;
    cin >> a >> b;
    int xk ,yk ,xq,yq ;
    cin >> xk >> yk >> xq >> yq;
    set<pair<int,int>> s ,t ;
    for(int i=0 ;i < 4 ; i++ ) {
        s.insert({xk +  dx[i] *a , yk + dy[i] *b });
        t.insert({xq + dx[i] *a ,  yq + dy[i] *b});
        s.insert({xk +  dx[i] *b , yk + dy[i] *a });
        t.insert({xq + dx[i] *b ,  yq + dy[i] *a});
    }
    int ans=0;
    for(auto it : s) {
        if(t.find(it ) != t.end()) {
            ans  ++ ;
        }
    }

    cout <<ans << endl ;
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