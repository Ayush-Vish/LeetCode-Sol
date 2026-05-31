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
struct MyDS {
    bool  first;
    vector<int> second;

    MyDS(bool  a, int b, int c, int d) : first(a), second({b, c, d}) {}
};

MyDS check(string s , int n ) {
    int iIndex = INT_MIN; 
    int jIndex = INT_MIN;
    int kIndex =  INT_MIN;
    bool ii = false;
    bool jj = false;
    bool kk = false;
    MyDS ds(false , INT_MIN ,INT_MIN,INT_MIN); 

    for( int i = s.size() -1 ; i >= 0 ; i -- ) {
        if(!ii && s[i] == 'a') {
            iIndex = i ;
            ii  = true;

        }
         if(!jj && s[i] == 'b') {
            jIndex = i ;
            jj  = true;
            
        }
         if(! kk  && s[i] == 'c') {
            kIndex= i ;
            kk  = true;
            
        }
    }


    ds.first = iIndex< jIndex  && jIndex<kIndex; 
    ds.second[0] = iIndex;
    ds.second[1] = jIndex;
    ds.second[2] = kIndex;

    return ds ;

}
void solve()
{
    int n ;
    cin >> n;
    string s ;
    cin >> s;

    
    if(!check(s,n).first  || s.size() <=2   )   {
        cout << 0 << endl ;
        return ; 

    }
    for( int  i=0 ;i < n ;i ++ ) 
    {
    
   
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