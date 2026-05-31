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

vector<vector<int>> mt;
vector<vector<int>> stime ;
vector<vector<int>> vis;
vector<vector<pll>> parent ;
vector<vector<char>> dir;

vector<vector<char>> grid ;
char dirs[] = {'D','R','U','L'};

int n,m;
bool ok(int i, int j )  {
    if(i < n && i>=0 && j < m && j>=0 ) {
        return true;
    }
    return false;

}

void bfsMonster(queue<pll>&q ) {
    while(!q.empty()) {
        auto p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int k=0 ; k < 4 ; k ++ ) {
            int nx = x  + dx[k];
            int ny =y + dy[k];
            if (ok(nx, ny) && grid[nx][ny] != '#' && mt[nx][ny] > mt[x][y] + 1) {
                mt[nx][ny] = mt[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
pll endc;

int bfs(pll start ) {
    queue<pll> q ;

    q.push(start);
    vis[start.first][start.second] = 1;
    stime[start.first][start.second] = 0;

    while(!q.empty()) {
        int  x = q.front().first;
        int y =  q.front().second;
        q.pop();
        if(x == 0 || y == 0 || x == n -1 || y == m-1  ) {
            endc = {x , y };
            return 1;
        }
        for(int k =0 ; k < 4 ; k ++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(ok(nx,ny) && !vis[nx][ny] && grid[nx][ny] != '#') {
                if(stime[x][y] + 1 < mt[nx][ny] ) { 
                    stime[nx][ny] = stime[x][y] +1 ;
                    vis[nx][ny ]=1 ;
                    parent[nx][ny] = {x,y};
                    dir[nx][ny]  =dirs[k];
                    q.push({nx,ny});
                }
            }
        }
    }
    return 0 ;

}


void solve(){
    cin >> n >> m ;
    grid.resize(n,vector<char>(m));
    vis.resize(n,vector<int>(m));
    
    mt.resize(n,vector<int>(m, INF));
    stime.resize(n,vector<int>(m,INF));
    dir.resize(n,vector<char>(m));
    parent.resize(n,vector<pll>(m));

    for(int i=0;i<n;i++) {
        for(int j=0; j < m ; j++ ){
            cin >> grid[i][j];
        }
    }

    queue<pll> mq ;
    pll start ;
    for(int i=0 ;i  < n ;i ++ ) {
        for(int j=0 ; j < m ;j ++ ) {
            if(grid[i][j] == 'M'){
                mq.push({i,j});
                mt[i][j] = 0;

            }else if (grid[i][j] == 'A') {
                start = {i,j};
            }
        }
    }
    if(start.first == 0 || start.second == 0 || start.first == n-1 || start.second == m-1) {
        cout << "YES\n0\n";
        return;
    }

    bfsMonster (mq );
    vis.assign(n,vector<int>(m,0));

    if(bfs(start)) {
        string path = "";
        while(endc != start) {
            path += dir[endc.first][endc.second];
            endc = parent[endc.first][endc.second];
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(),path.end());
        for(auto it : path ) {
            cout << it  ;
        } 
    }else {
        cout << "NO" << endl;
    }
    
     
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    // ci/n >> t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10) << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
