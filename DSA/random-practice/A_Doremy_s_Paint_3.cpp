#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
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
    vector<int> a(n);
    takeInput(a, n);
    unordered_map<int,int> mpp;
    bool flag = true;
    for(auto it :a ) {
        mpp[it] ++ ;
        if(mpp.size() >2) {
            flag = false;
        }
      
    }

  
  if(mpp.size() ==2 ) {
       int f1= begin(mpp)->second ;
       if(f1 != n/2 && f1!=(n+1)/2) {
        flag =false;
       }
     }

     if(flag) {
        cout << "YES"<<endl;
     }else {
        cout <<"NO"<<endl;
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