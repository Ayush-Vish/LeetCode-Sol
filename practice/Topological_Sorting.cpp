#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

vector<int> vis;
void dfs(int src, vector<int>adj[], stack<int>&st) {
vis[src] =1;
for(auto it : adj[src]) {
if(!vis[it]) {
dfs(it , adj,st);
}
}
st.push(src);
}
void solve(){
int n,m;
cin >> n >> m ;
vis.resize(n+1,0);
vector<int> adj[n+1];
for(int i=0 ;i < m ;i ++){
int a,b ;
cin >> a >>b ;
adj[a].push_back(b);
}
stack<int>st;
for(int i=1; i <= n ;i ++) {
if(!vis[i])
dfs(i,adj,st);
}
if(st.size() != n) {
cout << "Sandro fails." << endl;
}else {
vector<int> ans ;

while(!st.empty()) {
ans.push_back(st.top());
st.pop();
}
reverse(ans.begin(),ans.end());
for(auto it : ans) {
      cout << it << " " ;

}
}

}
bool multi = false;
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);    
cout.tie(NULL);
int t = 1;
if(multi) cin >> t;
while(t--){
solve();
}
return 0;
}
