#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long ans = n;
        for (long long i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                cerr << i << " "  << endl;
                if (i <= k) {
                    ans = min(ans, n / i);
                }
                if (n / i <= k) {
                    ans = min(ans, i);
                }
                cerr  << "ans "  << ans << endl;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}
