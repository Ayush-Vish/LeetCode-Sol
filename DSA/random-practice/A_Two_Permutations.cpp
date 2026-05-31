#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
class DSU {int size; vector<int> parent ,rank;DSU(int size ) {this->size = size;parent.resize(size+1);rank.resize(size +1 ) ;}int findUltimateParent(int node) {if(node == parent[node]) {return node;}return parent[node] = findUltimateParent(parent[node]) ;      }void unionByRank  (int a , int b ) {int ulp_a = findUltimateParent(a);int ulp_b = findUltimateParent(b) ;if(ulp_a ==ulp_b ) {return ;}if(rank[ulp_a] > rank[ulp_b]) {parent[ulp_b] = ulp_a ;}else  if(rank[ulp_a] < rank[ulp_b]){ parent[ulp_a] = ulp_b;}else {parent[ulp_a] = ulp_b;rank[ulp_b] ++ ;}}};
bool checkSorted(vector<int> &a) { for (int i = 0; i < a.size() - 1; i++) { if (a[i] > a[i + 1]) return false; } return true; } template <typename T> void takeInput(vector<T> &a, int n) { for (int i = 0; i < n; i++) { T ele; cin >> ele; a[i] = ele; } } template <typename T> void printArr(vector<T> &a) { cout << endl; for (auto it : a) { cout << it << " "; } cout << endl; }
void solve  ()
{

     int n , a, b ;
     cin >> n >>a >>b ; 
     if((a==n) && b==n ) {
        cout << "Yes" <<endl;
     }else if((a+b+2) <=  n) {
        cout << "Yes"<< endl;
     }else {
        cout << "No" << endl;
     }

}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}