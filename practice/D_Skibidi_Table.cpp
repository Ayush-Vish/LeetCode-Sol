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
vector<int> seive(int n) { vector<int> prime(n+1, 1); for(int i=2; i*i<=n; i++) if(prime[i]) for(int j=i*i; j<=n; j+=i) prime[j]=0; return prime; }
template <typename T> void takeInput(vector<T> &a, int n) { for(int i=0; i<n; i++) { T ele; cin>>ele; a[i]=ele; } }
template <typename T> void printArr(vector<T> &a) { for(auto it:a) cout<<it<<" "; cout<<endl; }
int fastPow(int a, int b) { int res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }

pair<int,int> p;
void f (int r, int c, int off, int size , int x , int y ) {
      if(r == x && c == y ) {
            p.first = off;
            return;
      }
      if(size ==1  ) return;
      int h = size/2;
      int area = h*h;
      f(r, c , off,h, x , y) ;
      f(r + h , c+h  , off + area,h, x , y) ;
      f(r + h , c , off + area*2 ,h, x , y) ;
      f(r, c + h , off + area*3 ,h, x , y) ;
}
void f2(int r, int c, int off, int size, int d) {
      if ( off == d) {
          p.first = r + 1;
          p.second = c + 1;
          return;
      }
      
      if (size == 1) return;
      int h = size / 2;
      int area = h * h;
  
      if (d >= off && d < off + area) {
          f2(r, c, off, h, d);
      } else if (d >= off + area && d < off + 2 * area) {
          f2(r + h, c + h, off + area, h, d);
      } else if (d >= off + 2 * area && d < off + 3 * area) {
          f2(r + h, c, off + 2 * area, h, d);
      } else {
          f2(r, c + h, off + 3 * area, h, d);
      }
  }
void solve(){
      int n ,q ;
      cin >> n >> q ;
      while (q-- ){
            string s ;cin >> s ;
            if(s == "->") {
                  int x, y ;
                  cin >> x >> y ;
                  f(0,0,1,1 << n ,x -1,y -1 );
                  cout << p.first << endl;
            }else {
                  int d ; cin >> d ;
                  f2(0,0,1,1 << n , d ) ;
                  cout << p.first<< " " << p.second <<endl;
                  
            }
      }
      
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
