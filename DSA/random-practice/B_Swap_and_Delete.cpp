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
   string s;
   cin >> s;

   
    int count [2] = {0,0} ;    
    int ans  =0 ;
    int n = s.size(); 

    for(int i =0 ;i < n ;i ++ ) {
        count[s[i] -'0']  ++ ; 
    }
    for(int i =0 ;i <s.size();i ++) {
        if(  count[!  int(s[i] -'0')]  > 0     ) {
            count[!int(s[i] -'0')] --;
        } else {
            ans = n-i;
            break;
            
            
        }
    } 
   cout <<ans  <<endl;
    

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