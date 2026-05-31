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
    bool seive(int n){memset(prime, 1, n+1);for(int i=2;i*i<n;i++)if(prime[i]==1)for(int j=i*i;j<=n;j+=i)prime[j]=0;}
    bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) {  cin >> a[i]; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
    void solve()
    {
        // Write your greatness here
        int n,k ;
        cin >> n >> k ;
        vector<int> arr(n );
        takeInput(arr,n);
        sort(arr.begin(),arr.end());
        int maxi = arr.back();
        int mini = arr.back() + k -1 ;
        for (int i=0 ; i< n -1  ;i ++ ) {
            int s = arr.back();
            int e =s + k;
            int ans ;

            if(((arr.back() - arr[i] )/ k) %2 ==1 )  {
                while(s<=e ) {
                    int mid = (s +e )/2;
                    if(((mid- arr[i]) /k) %2 == 1) {
                        s =mid +1 ;

                    }else {
                        ans = mid ;
                        e = mid  -1 ;

                    }
                }
                maxi = max(maxi ,ans ) ;

            }else {
                while (s<=e )
                {
                    int mid =(s+e)/2;
                    if(((mid-arr[i] )/k)%2 ==1 ) {
                        e= mid -1 ;

                    }else {
                        ans = mid ;
                        s= mid +1 ;

                    }
                    /* code */
                }
                mini= min(mini,ans);

                
            }

        }



        if(maxi<= mini) {
            cout<< maxi<<endl;
            return;
        }
        cout << -1 << endl;


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