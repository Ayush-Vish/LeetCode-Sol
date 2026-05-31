#include <bits/stdc++.h>
using namespace std;
#define intt long long int
intt MODU= 1e9+7;
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
intt f(intt index, intt k, intt b , vector<intt> &dp)
{
      if (index >b ) {
            return 1e9;
      }
      if(index == b ) {
            return 0 ;
      }

      if(dp[index ] != -1 ) {
            return dp[index];
       }


      intt way2 =(1+ f(index*k , k , b ,dp   ) )%MODU;
      intt way1 = 1e9 ;

      if(b-index<k ) {

      way1 = (1+ f(index +1 , k , b ,dp  ))%MODU ;
      }
      return dp[index] =  min(way1, way2) ;
}
void solve()
{
      intt a, b, k;
      cin >> a >> b >> k;
     
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