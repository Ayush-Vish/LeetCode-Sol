#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
void takeInput(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        a[i] = ele;
    }
}
void printArr(vector<int> &a)
{
    cout << endl;
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}
void solve()
{
      int x , y ;
      cin >> x >> y ;
      int ans  =0 ;
      while(y--) {
            x+= max(x+1000 , 2*x);
      }
      cout << x << endl;
   
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