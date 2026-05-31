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

   vector <int> v(n);
   takeInput(v, n ) ;
   sort(v.begin() , v.end()) ;
    int ans1=0 ;
    int ans2 =0 ;
    int i=0;
    int j = n-1;
 
    if(n %2 ==0 ) {

        while(i<j) {
            ans1 +=v[j] ;
            ans2 +=v[i];
            i ++;

            j --;

        }
    }else { 
            ans1 += v[j];
            j -- ;
            
            while(i<j) {
            ans1 +=v[j] ;
            ans2 +=v[i];
            j --;
            
            i ++;


        }
    }
   
   cout <<ans1-ans2 << endl;


   
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