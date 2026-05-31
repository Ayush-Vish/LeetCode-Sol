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
            int n = s.size();

            string  ans;
            ans.push_back(s[0]);
            
            ans += (to_string(s.size( ) -2 ));
            ans.push_back(s[n-1]);
            if(s.size()> 10) {

                  cout << ans << endl;
            }else {
                  cout << s << endl;
            
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