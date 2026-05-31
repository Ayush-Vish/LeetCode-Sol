#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    vector<int> pre(n, 1);

    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i]) {
            pre[i] = pre[i - 1] + 1;
        }
        ans = max(ans, pre[i]);
    }

    for (int i = 0; i < n; i++) {
        int newVal = a[i] * x;
        int leftStreak = (i > 0 && a[i - 1] <= newVal) ? pre[i - 1] : 0;
        int rightStreak = 1;

        int prev = newVal;
        for (int j = i + 1; j < n; j++) {
            if (prev <= a[j]) {
                rightStreak++;
                prev = a[j];
            } else {
                break;
            }
        }

        ans = max(ans, leftStreak + rightStreak);
    }

    cout << ans << endl;
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
