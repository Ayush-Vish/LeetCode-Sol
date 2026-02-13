#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * cute if -> regular(s) or regular(rev(s))
 * 
 * s = (((   ))))(
 * rs = ())))(((

 */

 /**
  * Proof:
  * 
  */

void solve(){
    int n ;
    cin>>n;
	string s;
	cin>>s;
	if(n%2==1){
		cout<<"-1\n";
		return;
	}
	int cur=0;
	int mx,mn;
	mx=mn=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			cur++;
			mx=max(mx,cur);
		}
		else{
			cur--;
			mn=min(mn,cur);
		}
	}
	if(cur!=0){
		cout<<"-1\n";
		return;
	}
	if(mn==0||mx==0){
		cout<<"1\n";
		for(int i=0;i<n;i++){
			cout<<"1 ";
		}
		cout<<'\n';
		return;
	}
	cout<<"2\n";
	for(int i=0;i<n;i++){
		if((s[i]=='('&&i<n/2)||(s[i]==')'&&i>=n/2))
		cout<<"1 ";
		else
		cout<<"2 ";
	}
	cout<<'\n';
    
}
bool multi = true;
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
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
