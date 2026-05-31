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
      int n ;
      cin >> n; 
      vector<int> arr(n);
      takeInput(arr,n);
      int maxi = 0;
      for(int i=0;i<n ;i ++) {
            for(int j=i;j<n;j++) {
                 
                  int sum = accumulate(arr.begin()+i,arr.begin()+j+1,0);
                  if(sum %2 ==0 ) {
                        maxi = max(maxi , abs(i-j) +1) ;
                  }
            }
      }
      cout <<maxi   <<endl;

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