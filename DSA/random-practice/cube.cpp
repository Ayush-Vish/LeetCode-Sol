#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve()
{
     // Write your greatness here
     int n ,f,k  ;
     cin >> n >>f >>k ;
     vector<int> arr(n);
     takeInput(arr,n);
    int fav = arr[f-1];

    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    int first  = false;
    int second = false;
    for(int i=0 ;i<k ;i ++ ) {
        if(arr[i] == fav) {
            first = true;
            break;
        }
    }
    for(int i= k; i<n ;i ++ ) {
        if(arr[i] == fav) {
            second = true;
            break;
        }
    }

    if(first && second) {
        cout << "MAYBE"<<endl;
    }else if(first && !second) {
        cout << "YES"<<endl;
    } else {
        cout << "NO"<<endl;
    }

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