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
   int arr[5][5]; 
   for(int i=0;i<5;i++) {
      for(int j=0 ;j <5 ;j ++ ) {
            cin >> arr[i][j];
            if(arr[i][j] ==1 ) {
                  cout <<abs(abs(i-2) +abs(j-2) )  <<endl;
                  return ; 
            }
      }
      
   }
   
}
int main()
{ 
      solve();
      return 0;
}