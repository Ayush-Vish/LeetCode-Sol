#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 * 
 */

/**
 * Proof:
 *
 */



void solve(){
    int l, r;
    cin >> l >> r;
    int ans = (r - l + 1);

    ans -= ((r / 2) - (l - 1) / 2);
    ans -= ((r / 3) - (l - 1) / 3);
    ans -= ((r / 5) - (l - 1) / 5);
    ans -= ((r / 7) - (l - 1) / 7);
    // [2,3,5,7]
    // 2*3 =6
    ans += (r / 6) - (l - 1) / 6;
    // 3*5 = 15
    ans += (r / 15) - (l - 1) / 15;
    // 5*7
    ans += (r / 35) - (l - 1) / 35;
    // 7*2
    ans += (r / 14) - (l - 1) / 14;
    // 7 *3
    ans += (r / 21) - (l - 1) / 21;
    ans += (r / 10) - (l - 1) / 10;

    // 2 3 5
    ans -= ((r / 30) - (l - 1) / 30);

    // 3 5 7
    ans -= ((r / 105) - (l - 1) / 105);

    // 5 7 2
    ans -= ((r / 70) - (l - 1) / 70);

    // 7 2 3
    ans -= ((r / 42) - (l - 1) / 42);

    // 2 3 5 7
    ans += (r / 210) - (l - 1) / 210;

    cout << ans << endl;
}
bool multi = true;
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
    {
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
