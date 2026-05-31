#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

struct Process {
    int id, at, bt, remaining;
};


struct Compare {
    bool operator()(const Process &a, const Process &b) const {
        if (a.remaining == b.remaining) return a.at > b.at; // FCFS tie-breaker
        return a.remaining > b.remaining; // Shortest Remaining Time First
    }
};

void solve() {
    // Input: AT and BT for P1 to P6
    vector<int> arrival = {0, 1, 2, 3, 4, 5};
    vector<int> burst   = {6, 4, 1, 2, 1, 3};
    int n = arrival.size();

    vector<int> ct(n), tat(n), wt(n);
    vector<int> remaining = burst;
    vector<bool> done(n, false);
    int currtime = 0, completed = 0;

    priority_queue<Process, vector<Process>, Compare> pq;

    while (completed < n) {
            // push karo till 
        for (int i = 0; i < n; ++i) {
            if (arrival[i] == currtime) {
                pq.push({i, arrival[i], burst[i], remaining[i]});
            }
        }

        if (!pq.empty()) {
            Process curr = pq.top(); pq.pop();
            // decrementing 1 
            curr.remaining--;
            remaining[curr.id]--;

            if (remaining[curr.id] == 0) {
                ct[curr.id] = currtime + 1;
                done[curr.id] = true;
                completed++;
            } else {
                pq.push({curr.id, curr.at, curr.bt, remaining[curr.id]});
            }
        }

        currtime++;
    }

    for (int i = 0; i < n; ++i) {
        tat[i] = ct[i] - arrival[i];
        wt[i] = tat[i] - burst[i];
    }

    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << i + 1 << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
