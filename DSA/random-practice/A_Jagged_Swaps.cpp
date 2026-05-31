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
      int n;
      cin >> n;
      vector<int> arr(n);
      takeInput(arr, n);
      
      int front = arr.front();
      for(int i=1;i<n ;i ++ ) {
            if(front- arr[i+1] < 0  ) {
                  cout <<"YES"<<endl;
                  return ;
            }
      }
      cout <<"NO"<<endl;

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