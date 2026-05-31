#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pll pair<int, int>

void solve(){
   vector<int> arrival = {0, 0, 1, 2, 3, 4, 6};
    vector<int> burst   = {6, 3, 4, 2, 1, 5, 2};
    int n = arrival.size();

    vector<int> ct(n), tat(n), wt(n);
    vector<bool> done(n, false);
    int completed = 0, currtime = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";

    while (completed < n) {
        for(int i=0 ;i < n ;i ++ ) {
            if( arrival[i] <= currtime && !done[i]) {
                pq.push({burst[i],i});
                done[i] = 1 ;

            }
        }
        if(pq.empty()) {
            currtime ++ ;
            continue;
        }
        auto [currProcessb , idx ] = pq.top();
        pq.pop();
        currtime += currProcessb;
        completed ++ ;
        ct[idx ]= currtime;
        tat[idx] = currtime - arrival[idx];
        wt[idx] = tat[idx] - burst[idx];


    }
    for(int idx =0 ; idx < n ;idx ++ ) {

        cout << idx + 1 << "\t" << arrival[idx] << "\t" << burst[idx] << "\t"
             << ct[idx] << "\t" << tat[idx] << "\t" << wt[idx] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto start = chrono::high_resolution_clock::now();
    solve();
    auto end = chrono::high_resolution_clock::now();

    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cerr << fixed << setprecision(10)
         << "Time measured: " << static_cast<double>(elapsed.count()) * 1e-9 << " seconds.\n";
    return 0;
}
