#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
void dfs(int node,int parent,vector<int> &dp,vector<int> &values,vector<vector<int>> &g,vector<bool> &primes){
    dp[node] = primes[values[node]];
    for(auto it : g[node]){
        if(it!=parent){
            dfs(it,node,dp,values,g,primes);
            dp[node]+=dp[it];
        }
    }
}
vector<int> tree(int n,vector<int> &first,vector<int> &second,vector<int> &values,vector<int> &queries){
    vector<bool> primes(1e5+1,true);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2;i<=1e5;i++){
        if(primes[i]){
            for(int j = i*i;j<=1e5;j+=i){
                primes[j] = false;
            }
        }
    }
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        g[first[i]-1].push_back(second[i]-1);
        g[second[i]-1].push_back(first[i]-1);
    }
    vector<int> dp(n);
    dfs(0,-1,dp,values,g,primes);
    vector<int> ans;
    for(int i=0;i<queries.size();i++){
        ans.push_back(dp[queries[i]-1]);
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    vector<int> first(n-1);
    for(int i=0;i<n-1;i++){
        cin>>first[i];
    }
    vector<int> second(n-1);
    for(int i=0;i<n-1;i++){
        cin>>second[i];
    }
    vector<int> values(n);
    for(int i=0;i<n-1;i++){
        cin>>values[i];
    }
    int q;
    cin>>q;
    vector<int> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    vector<int> ans = tree(n,first,second,values,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

