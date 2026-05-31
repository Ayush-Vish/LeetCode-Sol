#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<int, int>
const int modll = 1e17;
const int mod = 1e9 + 7;
const int INF = 1e18;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int prime[1];
bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;return true;}
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; }
template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } }
template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
/**
* Author: god_ayushv
*/
void solve()
{
    // Write your greatness here
    string s ;
    cin >> s;

    int ab =0 ,ba =0 ;
    for(int i=1 ;i < s.size();i ++) {
      if(s[i-1] == 'a' && s[i] == 'b') {
            ab ++ ;

      }
      if(s[i -1 ] == 'b' && s[i] == 'a') {
            ba ++ ;
      }
    }


      if(ab == ba ) {
            cout << s << endl;
      }


      else if(ab > ba ) {
            int diff = ab - ba ;
            for(int i=0 ; i < s.size() ;i ++ ) {
                  if(s[i] == 'a') {
                        s[i] = 'b';
                        diff-- ;

                  }


                  if(diff ==0 ) {
                        break;
                  }
            } 


            cout << s << endl;
       }else {
            int diff = ba -ab ;
            for(int i=0 ; i < s.size() ;i ++ ) {
                  if(s[i] == 'b') {
                        s[i] = 'a';
                        diff-- ;

                  }


                  if(diff ==0 ) {
                        break;
                  }
            } 


            cout << s << endl;
       }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}