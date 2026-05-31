#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353

int fastPow(int base, int exp, int mod = MOD) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos1, pos2, pos3;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) pos1.push_back(i);
        if (a[i] == 2) pos2.push_back(i);
        if (a[i] == 3) pos3.push_back(i);
    }

    if (pos1.empty() || pos2.empty() || pos3.empty()) {
        cout << "0\n";
        return;
    }

    int ans = 0;
    for (int i : pos1) {  
        auto it2 = upper_bound(pos2.begin(), pos2.end(), i);
        while (it2 != pos2.end()) {
            int j = *it2;
            auto it3 = upper_bound(pos3.begin(), pos3.end(), j);
            int count_3 = distance(it3, pos3.end());

            if (count_3 > 0) {
                int count_2_between = distance(it2, pos2.end()) - 1;
                ans = (ans + (count_3 * fastPow(2, count_2_between, MOD)) % MOD) % MOD;
            }
            ++it2;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
