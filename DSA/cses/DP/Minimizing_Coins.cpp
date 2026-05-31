#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // Use 1D DP array instead of 2D
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;  // Base case
    
    // For each sum
    for(int sum = 1; sum <= x; sum++) {
        // Try each coin
        for(int j = 0; j < n; j++) {
            // Prevent integer overflow by checking dp[sum - coins[j]] != INT_MAX
            if(coins[j] <= sum && dp[sum - coins[j]] != INT_MAX) {
                dp[sum] = min(dp[sum], dp[sum - coins[j]] + 1);
            }
        }
    }
    
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}