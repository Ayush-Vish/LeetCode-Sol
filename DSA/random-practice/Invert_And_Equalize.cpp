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
    string s;
    cin >> s;

    int oneCount = 0;
    int zeroCount = 0;

    for (int i = 1; i < n; i++)
    {
        if(i-1 ==0 ) {
            if(s[i-1] == '1') {
                oneCount  ++ ;
            }else {
                zeroCount  ++ ;
            }
        }
        if (s[i] != s[i - 1] && s[i] == '1')
        {
            oneCount++;
        }
        else if (s[i] != s[i - 1] && s[i] == '0')
        {
            zeroCount ++ ;
        }
    }
    cout <<min(oneCount  , zeroCount);
    cout <<endl;

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