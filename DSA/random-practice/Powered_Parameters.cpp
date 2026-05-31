#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    for (int i = 1; i <= n; i++)
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
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }

        return hash1;
    }
};
void solve()
{
    int n;
	    cin>>n;
	    vector<int> arr(n+1);
	    for(int i=1;i<=n;i++){
	        cin>>arr[i];
	    }
  

    long long count=0;
	    for(int i=1;i<=n;i++){
	        long long x=static_cast<long long>(arr[i]);
	        if(x==1){
	            count+=static_cast<long long>(n);
	        }
	        else{
	            long long power=1;
	            for(int j=1;j<=n;j++){
	                if(power>numeric_limits<long long>::max()/x){
	                    power=numeric_limits<long long>::max();
	                    break;
	                }
	                power*=x;
	                long long y=static_cast<long long>(arr[j]);
	                if(power<=y) count++;
	            }
	        }
	    }
	    cout<<count<<endl;
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