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
int f (int i ,int j ,string s , vector<vector<int>> &dp) {
      if(i==-11 || i== 11 || j==11 || j==-11) {
            return 0;
      }


      if(dp[i][j] != -1 ) {
            return dp[i][j];
      }
      int w1=0 ,w2=0,w3=0,w4=0;

      if(s[0] == '1') {
            w1 = 1+   f(i-1, j ,s,dp ) ;
      }
      if(s[1] == '1' ) {
            w2  =  1+   f(i+1, j , s,dp );
      }
      if(s[2] == '1' ) {
            w3 =  1+  f(i, j +1 , s ,dp);
      }
      if(s[3] == '1' ) {
            w2 =1 + f(i, j  -1 , s ,dp);
      }

      return dp[i][j] =  w1 + w2 +w3 + w4 ;
      

}     
void solve()
{
   string s;
   cin >> s;
   int one =0 ;

   for(auto it :s ) 
   {
      if(it =='1') {
            one ++ ;
      }
   }
   if(one == 0 ) {
      cout <<1<<endl;
   }
   else if(one == 1) {
      cout <<11<<endl;
   }else if(one ==2) {
      if(s[0] == '1'&& s[1] == '1' ) {
            cout <<21<<endl;
           
      }
      if(s[2] == '1'&& s[3] == '1' ) {
            cout <<21<<endl;
            
      }


      if(s[0] == '1' && s[2] == '1' ) {
            cout <<121<<endl;
            
      }
      if(s[0] == '1' && s[3] == '1' ) {
            cout <<121<<endl;
          
      }
      if(s[1] == '1' && s[2] == '1' ) {
            cout <<121<<endl;
            
      }
      if(s[1] == '1' && s[3] == '1' ) {
            cout <<121<<endl;
            
      }

   }
   else if(one ==3 ) {
      cout <<231<<endl;
   }else {
      cout <<441<<endl;
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