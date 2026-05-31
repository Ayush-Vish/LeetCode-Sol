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
        int n , x ;
        cin >> n >> x ;

        vector<int> arr(n);
        takeInput(arr,n);
        int dis1= 2*(x-arr[n-1]);
        int ans = INT_MIN;
        ans=max(ans , dis1);
        for(int i =n-1 ;i>=1 ;i--) {
            ans = max(arr[i] -arr[i-1] , ans ) ;
        }
        cout << max(arr[0],ans) <<endl;
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