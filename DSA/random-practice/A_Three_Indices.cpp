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
     int n ;
     cin >> n;
      vector<int> arr(n);
      takeInput(arr, n ) ;
      for(int i=0; i <n-2 ; i ++ ) {
            int j= i+1 ;
            int k = n-1;
            while(j<k) {
                  if(arr[j] > arr[k] && arr[i] < arr[j]) {
                        cout << "YES"<<endl;
                        cout << i +1 << " " << j +1  << " " <<  k +1 << endl ;
                        return ;
                  } else if(arr[k]  > arr[j]) { 
                        k -- ;


                  }else {
                        j ++ ;
                  }
            }
      }
      cout << "NO"<< endl;
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